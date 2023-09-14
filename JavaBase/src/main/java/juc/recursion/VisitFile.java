package juc.recursion;
import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.Callable;
import java.util.concurrent.FutureTask;

public class VisitFile {
    /**
     * 获取某个目录下所有文件名,以文件夹分组
     *
     * @param pathStr
     * @return
     */
    public static List<Map> getAllFilePathGroupFolder(String pathStr) {
        System.out.println("开始扫描："+ pathStr);
        Long nowTime = new Date().getTime();
        String str = pathStr;
        ScanFolderToFolderMap a = new ScanFolderToFolderMap(str);
        FutureTask<List<Map>> b = new FutureTask<List<Map>>(a);
        Thread worker = new Thread(b,str);
        worker.start();
        List<Map> c = null;
        try {
            c = b.get();
        } catch (Exception e) {
            e.printStackTrace();
            c = new ArrayList();
        }
        System.out.println("全部扫描结束,共扫描文件夹：" + c.size() + ",用时" + (new Date().getTime() - nowTime));
        return c;
    }

    public static void main(String[] args) {
        getAllFilePathGroupFolder("D:\\C++");
    }
}

class ScanFolderToFolderMap implements Callable<List<Map>>{

    //存储当前线程数量
    private static Integer sumJob = 0 ;

    private String folderPath = "";

    /**
     * 初始化一个线程
     * @param folderPath
     */
    public ScanFolderToFolderMap(String folderPath){
        this.folderPath = folderPath;
    }


    /**
     * 线程执行内容
     */

    public List<Map> call() throws Exception {
        sumJob++;
        Long nowTime = new Date().getTime();


        //准备返回的路径
        List<Map> reArr = new ArrayList<Map>();

        //获取路径
        // 校验路径是否有问题
        try {
            File file = new File(folderPath);
            if ((!file.isDirectory()) && (!file.isFile())) {
                return null;
            }
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }

        // 该目录下所有文件
        List<String> reFileArr = new ArrayList<String>();

        // 获取路径
        File file = new File(folderPath);

        // 获取文件夹内容以及判断是否有权限
        File[] sonFileArr = file.listFiles();
        if (sonFileArr == null){
            System.out.println("无权限");
            return null;
        }

        //准备子线程列表
        List<FutureTask<List<Map>>> workList = new ArrayList<FutureTask<List<Map>>>();

        //判断是否有子文件夹
        for(File fileObj:sonFileArr){
            if(fileObj.isFile()){
                //文件就添加路径
                reFileArr.add(fileObj.getAbsolutePath());
            }else{
                if(sumJob >= 10){
                    try {
                        //等带当前线程处理
                        Thread.currentThread().sleep(sumJob*100);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }


                //文件夹就继续解析
                ScanFolderToFolderMap a = new ScanFolderToFolderMap(fileObj.getAbsolutePath());
                FutureTask<List<Map>> b = new FutureTask<List<Map>>(a);
                workList.add(b);
                Thread worker = new Thread(b,fileObj.getAbsolutePath());
                worker.start();
            }
        }

        //获取所有线程返回信息
        for(FutureTask<List<Map>> workObj:workList){
            try {
                List<Map> mapArr = workObj.get();
                if (mapArr != null) {
                    reArr.addAll(mapArr);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        if (reFileArr.size() != 0) {
            Map fileMap = new HashMap();
            fileMap.put("folderName", file.getName());
            fileMap.put("folderPath", folderPath);
            Collections.sort(reFileArr);//对list集合进行排序
            fileMap.put("folderFiles", reFileArr);
            fileMap.put("date",file.lastModified());
            reArr.add(fileMap);
        }

        //返回扫描结果
        System.out.println((sumJob--) + ":扫描 " + folderPath + " 结束,用时" + (new Date().getTime() - nowTime));
        return reArr;
    }

}


