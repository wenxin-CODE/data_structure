#-*- codeing = utf-8 -*-

import bs4  #网页解析
import re   #文字匹配——正则
import urllib.request
import xlwt
import sqlite3

# https://www.bilibili.com/video/BV12E411A7ZQ/?p=41&spm_id_from=pageDriver&vd_source=2b2e3e59c887117a52c9dae9e753503c

# 定义爬取规则
findLink = re.compile(r'<a href="(.*?)">')
findImg = re.compile(r'<img.*src="(.*?)"',re.S) #re.S表示包含换行符
findTitle = re.compile(r'<span class="title">(.*)</span>')
findRating = re.compile(r'<span class="rating_num" property="v:average">(.*)</span>')
findJudge = re.compile(r'<span>(\d*)人评价</span>')
findInq = re.compile(r'<span class="inq">(.*)</span>')
findBd = re.compile(r'<p class="">(.*?)</p>',re.S)


# 爬取网页
def getdata(baseurl):
    datalist = []
    for i in range(0,10):
        url = baseurl+str(i*25)
        html = askURL(url)
        # 对网页进行逐一解析
        soup = bs4.BeautifulSoup(html,'html.parser')
        for item in soup.find_all('div',class_="item"):
            # print(item)
            data = []
            item = str(item) #string里进行正则选取
            link = re.findall(findLink,item)[0]
            data.append(link)
            img = re.findall(findImg,item)[0]
            data.append(img)
            title = re.findall(findTitle,item)[0]
            data.append(title)
            rate = re.findall(findRating,item)[0]
            data.append(rate)
            judge = re.findall(findJudge,item)
            data.append(judge)
            inq = re.findall(findInq,item)
            if(len(inq)!=0):
                inq = inq[0].replace("。","")
                data.append(inq)
            else:
                data.append(" ")
            bd = re.findall(findBd,item)[0]
            bd = re.sub('<br(\s+)?/>(\s+)?',' ',bd)
            bd = re.sub('/',' ',bd)
            data.append(bd.strip())
            datalist.append(data)
    # print(datalist)
    return datalist

# 保存数据到excel
def savedata(list,path):
    work = xlwt.Workbook("utf-8")
    sheet = work.add_sheet("top250",cell_overwrite_ok=True)
    title = ("链接","图片","名字","评分","评价","概况","相关信息")
    for i in range(len(title)):
        sheet.write(0,i,title[i])
    for i in range(len(list)):
        print("进行到"+str(i))
        data = list[i]
        for j in range(len(data)):
            sheet.write(i+1,j,data[j])
    work.save(path)

# 创建数据库
def init_DB(path):
    sql = '''
    create table movie250
    (
        id integer primary key autoincrement,
        info_link text,
        pic_link text,
        name varchar,
        score numeric,
        rated numeric,
        instroduction text,
        info text
    )
    '''
    conn = sqlite3.connect(path)
    cuesor = conn.cursor()
    cuesor.execute(sql)
    conn.commit()
    conn.close()

# 存储数据到数据库
def savedataDB(list,path):
    init_DB(path=path)
    conn = sqlite3.connect(path)
    cou = conn.cursor()

    for data in list:
        for index in range(len(data)):
            # 转成带引号的字符串
            print(str(data[index]))
            data[index] = '"'+str(data[index])+'"'
        sql = '''
            insert into movie250 (
                info_link,pic_link,name,score,rated,instroduction,info)
            values(%s)
        '''%",".join(data)
        # 用，连接元素
        cou.execute(sql)
        conn.commit()
    cou.close()
    conn.close()

# 获取网页信息
def askURL(url):
    header = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/110.0.0.0 Safari/537.36 Edg/110.0.1587.63"}
    req = urllib.request.Request(url,headers=header)
    try:
        res = urllib.request.urlopen(req)
        # print(res.read().decode("utf-8"))
    except urllib.error.URLError as e:
        if hasattr(e,"code"):
            print(e.code)
        if hasattr(e,"reason"):
            print(e.reason)

    return res

if __name__ == '__main__':
    # path="demo1.xlsx"
    list = getdata("https://movie.douban.com/top250?start=")
    # savedata(list,path)
    savedataDB(list,"movie.db")
    print("hello")
    