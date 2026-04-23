class Place:
    def __init__(self, name, cost, value):
        self.name = name
        self.cost = cost
        self.value = value

budget = int(input())

places = [
    Place("Goa", 5000, 10),
    Place("Manali", 3000, 7),
    Place("Jaipur", 2000, 5),
    Place("Kerala", 4000, 8)
]

places.sort(key=lambda p: p.value / p.cost, reverse=True)

total_value = 0.0

for p in places:
    if budget >= p.cost:
        budget -= p.cost
        total_value += p.value
        print(f"{p.name} FULL")
    else:
        fraction = budget / p.cost
        total_value += p.value * fraction
        print(f"{p.name} {fraction}")
        break

print(f"TOTAL {total_value:.2f}")
