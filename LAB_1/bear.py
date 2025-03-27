DONE_STR = "DONE"
MESSAGES = {
    True: "You won't be eaten!",
    False: "Uh oh..",
}


def main():
    done = False
    while not done:
        curr_input = input()
        if curr_input == DONE_STR:
            done = True
            break

        print(MESSAGES[solve(curr_input)])


def solve(data):
    sanitized = (
        data.replace(" ", "")
        .replace("?", "")
        .replace("!", "")
        .replace(".", "")
        .replace(",", "")
    )

    for idx in range(len(sanitized)):
        opp_idx = len(sanitized) - idx - 1
        if idx >= opp_idx or sanitized[idx].lower() == sanitized[opp_idx].lower():
            continue
        return False
    return True


def tests():
    def test_1():
        inputs = [
            "Madam, Im adam!",
            "Roma tibi subito motibus ibit amor.",
            "Me so hungry!",
            "Si nummi immunis",
        ]
        outputs = []

        for i in inputs:
            outputs.append(MESSAGES[solve(i)])

        assert outputs == [
            "You won't be eaten!",
            "You won't be eaten!",
            "Uh oh..",
            "You won't be eaten!",
        ]

    def test_2():
        inputs = ["   ", "  ", " ,", "socorram me subi no onibus em marrocos", "a Aba"]
        outputs = []

        for i in inputs:
            outputs.append(solve(i))

        assert outputs == [
            True,
            True,
            True,
            True,
            False,
        ]

    test_1()
    test_2()


# tests()
main()
