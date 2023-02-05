# python使用unicode编码，包含中英文，以及一些符号
# print逗号连接是空格，加号连接没空格


def one():
    # 输出到文件,w是覆盖，a是追加
    # fp = open('text1.txt','w')
    # print("good good study",file=fp)
    # print("good good study", file=fp)
    # print("good good study", file=fp)
    # fp.close()

    # 这里不用close
    with open('text1.txt','a') as file:
        file.write('day day up')

if __name__=='__main__':
    one()
