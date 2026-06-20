def hanoi(n, src, aux, dest):
    if n <= 0:
        return
    if n == 1:
        print(f"Move disk 1 from {src} to {dest}")
        return
    # Move n-1 disks from source to auxiliary
    hanoi(n - 1, src, dest, aux)
    # Move the largest disk to destination
    print(f"Move disk {n} from {src} to {dest}")
    # Move n-1 disks from auxiliary to destination
    hanoi(n - 1, aux, src, dest)
n = int(input("Enter number of disks: "))
if n <= 0:
    print("Number of disks must be greater than 0")
else:
    print(f"\nTotal moves required: {2 ** n - 1}\n")
    hanoi(n, 'A', 'B', 'C')