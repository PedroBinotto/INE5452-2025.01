MESSAGES = {True: "YES", False: "NO"}


def main():
    n_tests = int(input())
    for i in range(n_tests):
        _ = input()
        array_a = input().split(" ")
        array_b = input().split(" ")

        products = set()
        for el_a in array_a:
            for el_b in array_b:
                products.add(el_a + el_b)
        print(products)
        print(MESSAGES[len(products) >= 3])


main()
