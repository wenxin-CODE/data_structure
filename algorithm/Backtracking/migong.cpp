#include <stdio.h>
#include <stdlib.h>
#define N 10 // 迷宫大小
#define TRUE 1
#define FALSE 0

// 定义一个栈结构，用来存放路径
typedef struct {
    int x; // 行坐标
    int y; // 列坐标
    int dir; // 方向
} StackElem;

typedef struct {
    StackElem *base; // 栈底指针
    StackElem *top; // 栈顶指针
    int stacksize; // 栈的大小
} Stack;

// 初始化栈
void InitStack(Stack *S) {
    S->base = (StackElem *)malloc(N * N * sizeof(StackElem));
    if (!S->base) {
        printf("内存分配失败！\n");
        exit(1);
    }
    S->top = S->base;
    S->stacksize = N * N;
}

// 判断栈是否为空
int StackEmpty(Stack S) {
    if (S.top == S.base) {
        return TRUE;
    } else {
        return FALSE;
    }
}

// 入栈操作
void Push(Stack *S, StackElem e) {
    if (S->top - S->base >= S->stacksize) {
        printf("栈已满！\n");
        exit(1);
    }
    *S->top++ = e;
}

// 出栈操作
void Pop(Stack *S, StackElem *e) {
    if (S->top == S->base) {
        printf("栈为空！\n");
        exit(1);
    }
    *e = *--S->top;
}

// 获取栈顶元素
void GetTop(Stack S, StackElem *e) {
    if (S.top == S.base) {
        printf("栈为空！\n");
        exit(1);
    }
    *e = *(S.top - 1);
}

// 销毁栈
void DestroyStack(Stack *S) {
    free(S->base);
    S->base = NULL;
    S->top = NULL;
    S->stacksize = 0;
}

// 定义一个方向结构，用来表示上下左右四个方向
typedef struct {
    int x; // 行偏移量
    int y; // 列偏移量
} Direction;

// 定义四个方向的数组，顺序为上右下左
Direction move[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// 定义一个迷宫结构，用来存放迷宫的地图和标记
typedef struct {
    int maze[N][N]; // 迷宫地图
    int mark[N][N]; // 迷宫标记
} Maze;

// 从文件中读取迷宫地图
// 把char类型的变量改为const char类型的，这样就不会破坏字符串常量的不可修改性
void ReadMaze(Maze *M, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        // printf("打开文件失败！\n");
        //改变：这里并没有直接打印，而是换成了perror函数报告错误
        perror("打开文件test.txt失败啦");
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d", &M->maze[i][j]); // 读取迷宫地图
            M->mark[i][j] = 0; // 初始化迷宫标记
        }
    }
    fclose(fp);
}

// 打印迷宫地图
void PrintMaze(Maze M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", M.maze[i][j]);
        }
        printf("\n");
    }
}

// 打印迷宫路径
void PrintPath(Stack S) {
    StackElem e;
    printf("迷宫路径如下：\n");
    while (!StackEmpty(S)) {
        Pop(&S, &e); // 出栈
        printf("(%d, %d) ", e.x, e.y); // 打印坐标
    }
    printf("\n");
}

// 回溯法求解迷宫问题
void MazePath(Maze M, int x1, int y1, int x2, int y2) {
    // x1, y1为入口坐标，x2, y2为出口坐标
    Stack S; // 定义一个栈
    InitStack(&S); // 初始化栈
    StackElem e; // 定义一个栈元素
    e.x = x1; // 入口的行坐标
    e.y = y1; // 入口的列坐标
    e.dir = -1; // 入口的方向
    Push(&S, e); // 入口入栈
    M.mark[x1][y1] = 1; // 标记入口已走过
    int find; // 定义一个标志，表示是否找到可走的方向
    while (!StackEmpty(S)) { // 栈不为空时循环
        GetTop(S, &e); // 获取栈顶元素
        if (e.x == x2 && e.y == y2) { // 如果到达出口
            PrintPath(S); // 打印路径
            return; // 结束函数
        }
        find = FALSE; // 初始化标志为假
        for (int i = e.dir + 1; i < 4; i++) { // 从上一次的方向开始试探
            int x = e.x + move[i].x; // 下一个位置的行坐标
            int y = e.y + move[i].y; // 下一个位置的列坐标
            if (x >= 0 && x < N && y >= 0 && y < N && M.maze[x][y] == 0 && M.mark[x][y] == 0) { // 如果下一个位置可走
                find = TRUE; // 标志为真
                e.dir = i; // 更新栈顶元素的方向
                Push(&S, e); // 入栈
                M.mark[x][y] = 1; // 标记已走过
                e.x = x; // 更新下一个位置的行坐标
                e.y = y; // 更新下一个位置的列坐标
                e.dir = -1; // 初始化下一个位置的方向
                Push(&S, e); // 入栈
                break; // 跳出循环
            }
        }
        if (!find) { // 如果没有找到可走的方向
            Pop(&S, &e); // 出栈
            M.mark[e.x][e.y] = 0; // 取消标记
        }
    }
    printf("没有找到迷宫路径！\n");
}

// 主函数
int main() {
    Maze M; // 定义一个迷宫
    // 文件地址用绝对的
    ReadMaze(&M, "D:\\C++\\data_structure\\algorithm\\Backtracking\\maze.txt"); // 从文件中读取迷宫地图
    printf("迷宫地图如下：  \n");
    PrintMaze(M); // 打印迷宫地图
    MazePath(M, 0, 0, N - 1, N - 1); // 回溯法求解迷宫问题
    return 0;
}