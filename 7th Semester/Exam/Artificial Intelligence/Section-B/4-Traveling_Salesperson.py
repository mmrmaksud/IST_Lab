import itertools
# Function to calculate total cost of a route
def get_cost(route, graph):
    cost = 0
    for i in range(len(route) - 1):
        cost += graph[route[i]][route[i + 1]]
    # Return to starting city
    cost += graph[route[-1]][route[0]]
    return cost
# Function to solve TSP using Brute Force
def tsp(graph, start):
    cities = list(graph.keys())
    cities.remove(start)
    best_route = None
    best_cost = float('inf')
    # Generate all possible routes
    for perm in itertools.permutations(cities):
        route = [start] + list(perm)
        cost = get_cost(route, graph)
        if cost < best_cost:
            best_cost = cost
            best_route = route
    return best_route, best_cost
# Distance graph
graph = {
    'A': {'A': 0, 'B': 10, 'C': 15, 'D': 20},
    'B': {'A': 10, 'B': 0, 'C': 35, 'D': 25},
    'C': {'A': 15, 'B': 35, 'C': 0, 'D': 30},
    'D': {'A': 20, 'B': 25, 'C': 30, 'D': 0}
}
# Starting city
start = 'A'
# Solve TSP
best_route, min_cost = tsp(graph, start)
# Display result
print("===== Traveling Salesperson Problem (TSP) =====")
print("Best Route :", " -> ".join(best_route + [start]))
print("Minimum Cost:", min_cost)