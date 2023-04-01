import sqlite3

from flask import Flask, render_template

app = Flask(__name__)


@app.route('/')
def hello_world():
    return 'Hello World!'

# 返回渲染模板
@app.route('/index')
def index():
    return render_template("index.html")

@app.route('/movie')
def movie():
    datalist = []
    con = sqlite3.connect("movie.db")
    cur = con.cursor()
    sql = "select * from movie250"
    data = cur.execute(sql)
    for item in data:
        datalist.append(item)
    cur.close()
    con.close()
    return render_template("movie.html",movies = datalist)

@app.route('/team')
def team():
    return render_template("team.html")

@app.route('/score')
def score():
    score = []
    num = []
    con = sqlite3.connect("movie.db")
    cur = con.cursor()
    # 查询两个内容，用，隔开
    sql = "select score,count(score) from movie250 group by score"
    data = cur.execute(sql)
    for item in data:
        score.append(item[0])
        num.append(item[1])
    cur.close()
    con.close()
    return render_template("score.html",score=score,num=num)

@app.route('/word')
def word():
    return render_template("word.html")


if __name__ == '__main__':
    app.run()
