def hill_climbing(start):
    def objective(x):
        return -(x - 5) ** 2 + 25
    current = start
    while True:
        neighbors = [current - 1, current + 1]
        current_value = objective(current)
        best_neighbor = current
        best_value = current_value
        for n in neighbors:
            value = objective(n)
            if value > best_value:
                best_value = value
                best_neighbor = n
        if best_neighbor == current:
            break
        current = best_neighbor
    return current, objective(current)
start_point = 0
best_x, best_value = hill_climbing(start_point)
print("Best x =", best_x)
print("Maximum value =", best_value)