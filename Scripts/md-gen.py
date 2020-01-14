import os
import json


if __name__ == "__main__":

    def load_file():
        file = open("./Scripts/conf/md-columns.conf", encoding="utf-8")
        columns = file.read()
        file.close()

        file = open("./Scripts/conf/md-columns-map.conf", encoding="utf-8")
        columns_map = file.read()
        file.close()

        file = open("./Data/problems.json", encoding="utf-8")
        problems = file.read()
        file.close()

        file = open("./Data/solutions.json", encoding="utf-8")
        solutions = file.read()
        file.close()

        return problems, solutions, columns, columns_map

    def combination(problems, solutions, columns, columns_map):
        """将相关数据拼接在一起，方便后续使用，效率略低"""

        for problem in problems[:]:
            problem["solutions"] = [solution for solution in solutions
                                    if solution["id"] == problem["id"]][0]["solutions"]
        for column in columns[:]:
            column["map"] = columns_map[column["name"]]

        columns.sort(key=lambda item: int(item["rank"]))
        return problems, columns

    def markdown_row_template(num):
        """生产 MarkDown 行的模板"""
        template = ""
        for _ in range(num):
            template += "| {0[" + str(_) + "]} "
        template += "|"
        return template

    def markdown_head(columns):
        """构造 MarkDown 的头部"""
        template = markdown_row_template(len(columns))
        first = template.format([item["name"] for item in columns])
        second = template.format([item["align"] for item in columns])
        return first + "\n" + second + "\n"

    def markdown_content(problems, columns):
        """构造 MarkDown 的内容"""
        template = markdown_row_template(len(columns))
        keys = [column["map"] for column in columns]

        content = ""
        for problem in problems:

            def find_value(problem, key):
                """根据 key 获取 problem 中的 value 值"""
                sub_key = key.split(".")
                if sub_key[0] == "":
                    return problem
                return find_value(problem[sub_key[0]], ".".join(sub_key[1:]))

            values = []
            for key in keys:
                # 普通字段
                value = find_value(problem, key)
                if key.split(".")[0] != "solutions":
                    values.append(value)
                # 需要转换为链接
                else:
                    links = ""
                    for link in value:
                        file_name = os.path.splitext(os.path.basename(link))[0]
                        link = "/".join(link.split("/")[1:])
                        links += "[" + file_name + "](" + link + ")"
                        links.replace(" ", "%20")
                    values.append(links)

            content += template.format(values) + "\n"

        return content

    def generate_markdown(problems, columns):
        """构造 MarkDown 文件"""
        head = markdown_head(columns)
        content = markdown_content(problems, columns)
        return head + content

    def save_markdown(path, markdown):
        """保存 MarkDown 文件"""
        file = open("./Problems/" + path + "/" + "README.md", "w", encoding="utf-8")
        file.write(markdown)
        file.close()

    problems, solutions, columns, columns_map = load_file()

    problems = json.loads(problems)
    solutions = json.loads(solutions)
    columns = json.loads(columns)
    columns_map = json.loads(columns_map)

    problems, columns = combination(problems, solutions, columns, columns_map)

    # 大列表中切分为小列表
    n = 100
    matrix = [problems[i:i + n] for i in range(0, len(problems), n)]

    for index in range(len(matrix)):
        markdown = generate_markdown(matrix[index], columns)
        right = (index + 1) * 100
        left = right - 100 + 1
        save_markdown(str(left).zfill(4) + "-" + str(right).zfill(4), markdown)
