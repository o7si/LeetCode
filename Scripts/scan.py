import os
import math
import json


if __name__ == "__main__":

    def dir_name(problem):
        """获取题目对应的目录路径"""
        right = math.ceil(int(problem["id"]) / 100) * 100
        left = right - 100 + 1

        first = str(left).zfill(4) + "-" + str(right).zfill(4)
        second = problem["id"].zfill(4) + ". " + problem["title"]

        return first + "/" + second + "/"


    def scan_solutions(dir_name):
        """扫描题目的题解"""
        # 编程语言的类型
        languages = ["C++", "Java", "Python", "C",
                     "C#", "JavaScript", "Ruby", "Swift",
                     "Go", "Scala", "Kotlin", "Rust",
                     "PHP"]
        # 保存所有语言的题解
        solutions = {}
        for language in languages:
            solution_dir = dir_name + language + "/"
            # 不存在对应目录
            if not os.path.exists(solution_dir):
                continue
            # 存在对应目录
            lang_solution = []
            # 除 empty.* 之外的文件均认为是题解
            files = os.listdir(solution_dir)
            for file in files:
                # 忽略目录
                if os.path.isdir(os.path.join(solution_dir, file)):
                    continue
                # 忽略 empty.* 的文件
                if os.path.splitext(file)[0] == "empty":
                    continue
                lang_solution.append(solution_dir + file)

            solutions[language.lower()] = lang_solution

        return solutions

    file = open("./Data/problems.json", "r", encoding="utf-8")
    problems = file.read()
    file.close()

    os.chdir("./Problems/")
    json_problems = json.loads(problems)
    problems_solutions = []
    for item in json_problems:
        problem_solutions = {
            "id": item["id"],
            "solutions": scan_solutions(dir_name(item))
        }
        problems_solutions.append(problem_solutions)

    os.chdir("../")
    save = json.dumps(problems_solutions, sort_keys=True, indent=2, separators=(', ', ': '))
    file = open("./Data/solutions.json", "w", encoding="utf-8")
    file.write(save)
    file.close()
