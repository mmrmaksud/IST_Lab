list1 = [1, 2, 3, 4, 7.3]
list2 = [3, 4, 5, 6]
union = list(set(list1) | set(list2))
intersection = list(set(list1) & set(list2))
print("Union =", union)
print("Intersection =", intersection)