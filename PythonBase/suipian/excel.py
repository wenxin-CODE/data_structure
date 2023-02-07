import xlrd
import xlwt
import pandas as pd
import numpy as np
#
#
# def write_excel():
#     data = [['title1', 'content1'], ['test2', 'test3']]
#     # 创建excel
#     wb = xlwt.Workbook()
#     # 创建excel中的sheet
#     ws = wb.add_sheet('test')
#     for i in range(len(data)):
#         for j in range(len(data[i])):
#            ws.write(i, j, data[i][j])
#     # ws.write(0, 0, 'hahah')
#     wb.save('G:/python/test.xls')
#
# def get_excel():
#     # 获取数据
#     data = xlrd.open_workbook('G:/python/test.xls')
#     # 获取sheet
#     # table = data.sheet_by_name('test') # 通过sheet名称获取数据
#     table = data.sheet_by_index(0)   # 通过sheet索引获取数据
#     # 获取总行数
#     rows = table.nrows
#     # 获取总列数
#     cols = table.ncols
#     # 获取某个单元格的数据
#     cell_value = table.cell(0, 1).value
#     print(cell_value)
#     # 获取excel表格所有数据
#     for i in range(rows):
#         for j in range(cols):
#             print(table.cell(i, j).value)
#
# write_excel()
#
# # 读取Excel中长方形长和宽，计算外接圆面积，并写入Excel
# def get_area(l,h):
#     return (np.sqrt(l**2+h**2))**2*np.pi
#
# def wrapper(row):
#     return  get_area(row['Length'],row['Height'])
#
# ret = pd.read_excel("G:\\python\\one.xlsx")
# ret['CA'] = ret.apply(wrapper,axis=1)#DataFrame添加列
# ret.to_excel("G:\\python\\one.xlsx")#DataFrame写入Excel，注意文件不能打开

# ---------------------------------------
page_1 = pd.read_excel("G:\\python\\one.xlsx")
page_2 = pd.read_excel("G:\\python\\two.xlsx")
# concat合并两张表为list，drop=True删除原索引
student = pd.concat([page_1,page_2]).reset_index(drop = True)
print(student)
print("---------------------")
# students = pd.concat([page_1,page_2],axis=1).reset_index(drop=True)
# print(students)

# 添加一列
student['Age'] = np.repeat(25,len(student))
print(student)

# 删除列
student.drop(columns=["Age"],inplace=True)
print(student)

# 插入列
student.insert(1,column="FOO",value=np.repeat('foo',len(student)))
print(student)

# 改列名
student.rename(columns={"FOO":"Foo"},inplace=True)
print(student)

# 删除空值
student.dropna(inplace=True)
print(student)