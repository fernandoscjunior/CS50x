def main():
    while True:
        try:
            card_number = int(input("Card Number:"))
            if (card_number > 0):
                break
        except:
            print("Invalid")

    if valid_size(card_number):
        result = luhn_algorithm(card_number)
        if result != 0:
            brand = card_type(card_number)
            print(brand)
        else:
            print("INVALID")
    else:
        print("INVALID")


def valid_size(card_number):
    cardlen = len(str(card_number))

    # Verifies if card number has valid length
    if cardlen != 13 and cardlen != 15 and cardlen != 16:
        return False
    else:
        return True


def luhn_algorithm(card_number):
    total = 0
    string_card = str(card_number)
    size = len(string_card)

    for digit in range(size):
        last_digit = int(string_card[size - digit - 1])

        if digit % 2 == 0:
            total += last_digit
        else:
            if last_digit * 2 >= 10:
                two_times = last_digit * 2
                total += two_times % 10
                total += 1
            else:
                total += last_digit * 2

    return total % 10 == 0


def card_type(card_number):
    card_string = str(card_number)
    first_digit = int(card_string[0])
    second_digit = int(card_string[1])

    if first_digit == 4:
        return "VISA"
    elif first_digit == 3 and (second_digit == 4 or second_digit == 7):
        return "AMEX"
    elif first_digit == 5 and (second_digit >= 1 and second_digit <= 5):
        return "MASTERCARD"
    else:
        return "INVALID"


main()
