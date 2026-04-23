import subprocess

budget = input("Enter your budget: ")

process = subprocess.Popen(
    ["py", "knapsack.py"],   
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    text=True
)

output, _ = process.communicate(budget)

print("\nTrip Plan:\n")
lines = output.split("\n")

for line in lines:
    if "FULL" in line:
        name = line.split()[0]
        print(f"{name} (Full Visit)")
    elif "TOTAL" in line:
        total = line.split()[1]
        print("\nTotal Enjoyment Value:", total)
    elif line.strip():
        name, fraction = line.split()
        print(f"{name} ({float(fraction)*100:.1f}% Visit)")
