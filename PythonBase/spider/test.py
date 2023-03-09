#-*- codeing = utf-8 -*-

import bs4  #网页解析
import re   #文字匹配——正则
import urllib.request
import xlwt
import sqlite3

# 爬取网页
def getdata(baseurl):
    datalist = []
    for i in range(0,10):
        url = baseurl+str(i*25)
        askURL(url)
        # 对网页进行逐一解析


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
    getdata("https://movie.douban.com/top250?start=")
    print("hello")