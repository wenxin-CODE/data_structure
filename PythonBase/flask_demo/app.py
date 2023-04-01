import datetime

from flask import Flask,render_template,request

# Flask=werkzeug（处理路由）+jinja2（返回html）
# 创建flask框架，生成对象
app = Flask(__name__)
# 打开flask_debug，方便调试


# 路由解析，通过路径匹配函数
@app.route('/')
def hello_world():
    return 'Hello World!'

# # 带参访问
# # <>里面是传入的参数
# @app.route('/user/<name>')
# def hello(name):
#     return "hello "+name


# # 根据参数类型的不同，自动路由匹配不同的函数
# @app.route('/user/<int:id>')
# def welcome(id):
#     return "欢迎%d号顾客"%id

# # 接收的参数默认是str类型，返回的结果也必须是str类型
# @app.route('/add/<int:a>/<int:b>')
# def add(a,b):
#     # a=int(a)
#     # b=int(b)
#     return "结果是%d"%(a+b)

# # 返回渲染模板
# @app.route('/index')
# def index():
#     return render_template("index.html")

# # 返回参数给模板
# @app.route('/date')
# def date():
#     date = datetime.date.today()
#     names = ['mike','alice','bob']
#     task = {"洗碗":"30min","扫地":"20min"}
#     return render_template("index.html",var = date,list = names,task = task)

# # 提交表单
# @app.route('/test/register')
# def register():
#     return render_template("test/register.html")

# # 注意接收端要加method，表示接受啥请求。默认只接受get
# @app.route('/result',methods=['POST','GET'])
# def result():
#     if request.method == 'POST':
#         result = request.form  #这里form是一个字典
#         return render_template("test/result.html",result=result)

if __name__ == '__main__':
    app.run()
    
    # 制作流程：
    # 1爬取数据 spider BS4 urllib
    # 2数据保存 sqlite
    # 3搭建框架 路由 页面 CSS
    # 4制作图表 echarts.js / wordcloud
