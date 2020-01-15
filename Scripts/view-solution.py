import argparse
import json

parser = argparse.ArgumentParser(description='View LeetCode Solution.')
parser.add_argument('-n', type=int, help='Number of problem', required=True)
parser.add_argument('-l', type=str, help='Lang of solution. Support \n'
                                         '"C++", "Java", "Python", "C", "C#", "JavaScript", '
                                         '"Ruby", "Swift", "Go", "Scala", "Kotlin", "Rust", "PHP"',
                    required=True, default='C')

args = parser.parse_args()
lang = args.l.lower()
problem_id = args.n

with open('./Data/solutions.json') as f:
    solution = json.loads(f.read())
problem = solution[problem_id - 1]
solutions = problem['solutions'].get(lang, [])
for solution in solutions:
    with open('./Problems/' + solution) as code:
        print(code.read())
