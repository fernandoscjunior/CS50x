import csv
import sys
from collections import Counter


def main():
    arguments = len(sys.argv)

    if arguments != 3:
        print("Usage: python dna.py path_to_csv_file/ path_to_text_file/")
        return

    csv_file = sys.argv[1]
    text_file = sys.argv[2]

    # Getting csv content inside rows as lists
    rows = []
    with open(csv_file) as file:
        reader = csv.DictReader(file)

        for row in reader:
            rows.append(row)

    # Assigning file's line to genes
    genes = ""
    with open(text_file) as file:
        for row in file:
            genes = row

    # Checks every dna subsequences present on csv
    subsequences = []

    for row in rows:
        for item in row:
            if item == "name" or item in subsequences:
                continue
            subsequences.append(item)

    # Finds longest match of each STR in DNA sequence and adds it to big_matches
    big_matches = {}
    for subsequence in subsequences:
        big_matches[subsequence] = longest_match(genes, subsequence)

    # Checking database for matching profiles
    matches = []
    for row in rows:
        for item in row.items():  # item are key:value list
            for i in big_matches.items():
                if item[0] == i[0] and int(item[1]) == i[1]:
                    matches.append(row["name"])

    diff_matches = set(matches)

    for name in diff_matches:
        result = matches.count(name)
        if result == len(subsequences):
            print(name)
            return

    print("No Match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
