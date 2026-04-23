from flask import Flask, render_template, request

app = Flask(__name__)

class Place:
    def __init__(self, name, cost, value):
        self.name = name
        self.cost = cost
        self.value = value

@app.route('/', methods=['GET', 'POST'])
def home():
    result = []
    total_value = 0

    if request.method == 'POST':
        budget = int(request.form['budget'])

        names = request.form.getlist('name')
        costs = request.form.getlist('cost')
        values = request.form.getlist('value')

        places = []

        for i in range(len(names)):
            if names[i] and costs[i] and values[i]:
                places.append(Place(
                    names[i],
                    int(costs[i]),
                    int(values[i])
                ))

        # Apply Knapsack
        places.sort(key=lambda p: p.value / p.cost, reverse=True)

        for p in places:
            if budget >= p.cost:
                budget -= p.cost
                total_value += p.value
                result.append((p.name, "Full Visit"))
            else:
                fraction = budget / p.cost
                total_value += p.value * fraction
                result.append((p.name, f"{fraction*100:.1f}% Visit"))
                break

    return render_template("index.html", result=result, total=total_value)

if __name__ == '__main__':
    app.run(debug=True)
