import sqlite3
import urllib.request
import requests
from bs4 import BeautifulSoup
import re
from hyper.contrib import HTTP20Adapter

# 初始化数据库
def init_db(dbpath):
    sql = '''
        create table job
        (
            id integer primary key autoincrement,
            jlink text,
            jname text,
            cname varchar,
            area varchar,
            salary text,
            educate text,
            info text
        )
    '''
    con = sqlite3.connect(dbpath)
    cur = con.cursor()
    cur.execute(sql)
    con.commit()
    cur.close()
    con.close()

# 获取网页信息
def askURL(url):
    header = {
        ':authority': 'y.qq.com',
            ':method': 'GET',
           ':path': '/n/ryqq/search?w=%E8%AE%B8%E5%B5%A9&t=song&remoteplace=txt.yqq.center',
           ':scheme':' https',
            'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7',
            'accept-encoding': 'gzip, deflate, br',
            'accept-language': 'zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6',
            'cache-control': 'max-age=0',
            'cookie': 'RK=s5e1ZATccv; ptcz=23c34d2d46d5fc3f4e4f6384e9533965e53470248dddeb4a844bcc8ba99e6707; pgv_pvid=4275719828; pac_uid=0_7a88c36e1e02b; fqm_pvqid=8e3828cd-e77b-471e-9966-160792be5355; ts_refer=cn.bing.com/; ts_uid=8101057800; ptui_loginuin=2011429436; fqm_sessionid=160bdd7d-4511-4609-b80f-f61b27df86a1; pgv_info=ssid=s8601780688; _qpsvr_localtk=0.6381309221036451; login_type=1; psrf_qqunionid=B85098A55E27093D54186F2E3E4736DA; euin=own5oKvANKvi7c**; psrf_qqaccess_token=5540A43670FF2A6E5D49F4A2C0F21632; psrf_qqrefresh_token=B3D984D2C574BE29CE48FFEF9A70162E; qm_keyst=Q_H_L_5BxXMsADUQtF6jvKrwdsm7s2l2twXS25LyoA7wDxZlGcu9Sab0fvkLQ; psrf_musickey_createtime=1679882333; wxopenid=; psrf_access_token_expiresAt=1687658333; uin=2011429436; qm_keyst=Q_H_L_5BxXMsADUQtF6jvKrwdsm7s2l2twXS25LyoA7wDxZlGcu9Sab0fvkLQ; tmeLoginType=2; wxrefresh_token=; qqmusic_key=Q_H_L_5BxXMsADUQtF6jvKrwdsm7s2l2twXS25LyoA7wDxZlGcu9Sab0fvkLQ; wxunionid=; psrf_qqopenid=F5A93A80C90D7D1E647A8F941B6AC267; ts_last=y.qq.com/n/ryqq/mv/w0024o1berc',
            'referer': 'https://y.qq.com/n/ryqq/search?w=%E8%AE%B8%E5%B5%A9&t=song&remoteplace=txt.yqq.center',
            # 'sec-ch-ua': "Microsoft Edge";v="111", "Not(A:Brand";v="8", "Chromium";v="111"
            'sec-ch-ua-mobile': '?0',
            'sec-ch-ua-platform': "Windows",
            'sec-fetch-dest': 'document',
            'sec-fetch-mode': 'navigate',
            'sec-fetch-site': 'same-origin',
            'sec-fetch-user': '?1',
            'upgrade-insecure-requests': '1',
            'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/111.0.0.0 Safari/537.36 Edg/111.0.1661.54',
        }
    req = urllib.request.Request(url,headers=header)
    try:
        res = urllib.request.urlopen(req)
        html = res.read().decode("utf-8")
        # sessions=requests.session()
        # sessions.mount('https://pubmed.ncbi.nlm.nih.gov', HTTP20Adapter())
        # res=sessions.get(url,headers=header)
    except urllib.error.URLError as e:
        if hasattr(e,"code"):
            print(e.code)
        if hasattr(e,"reason"):
            print(e.reason)

    return html

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

if __name__ == "__main__":
    url = "https://y.qq.com/n/ryqq/search?w=%E8%AE%B8%E5%B5%A9&t=song&remoteplace=txt.yqq.center"
    html = askURL(url)
    bs = BeautifulSoup(html.text,"html.parser")
    result = bs.select('.songlist__icon songlist__icon_mv sprite')
    print(result)