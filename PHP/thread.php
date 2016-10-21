<?php
/**
 * Created by PhpStorm.
 * User: jiankang.wang
 * Date: 2016/10/21
 * Time: 9:52
 */
//���߳�ִ������
class Threads{
    protected $threads;
    protected $jobs;
    /**
     * init Threads
     */
    public function __construct($threadnum,$jobs){
        $this->jobs = $jobs;
        for($i = 0;$i < $threadnum;$i++){
            $this->threads[$i] = new childThread();
        }
//        $this->doJob();
    }
    /**
     * scan the thread
     * @return bool|@thread
     */
    public function scan(){
        $idleThreads = array();
        echo "��ǰ������:".count($this->jobs)."\n";
        if(count($this->jobs) <= 0){
            return 'no jobs';
        }
        foreach($this->threads as $key => $childThread){
            if($childThread->busy === false){
                $idleThreads[] = $childThread;
                if(count($idleThreads) >= count($this->jobs)){
                    break;
                }
            }
        }
        if(count($idleThreads) > 0){
            $this->doJob($idleThreads);
            return false;
        }else{
            return false;
        }
    }
    /**
     * execute thread job
     */
    public function doJob($idleThreads){
        foreach($idleThreads as $key => $childThread){
            $childThread->job = $this->getJob();
            if($childThread->isStarted()){
                echo $childThread->job." started\n";
            }else{
                $childThread->start();

            }

        }
    }
    /**
     * get thread job
     */
    public function getJob(){
        $job = $this->jobs[0];
        array_shift($this->jobs);
        return $job;
    }

}
class childThread extends Thread{
    public $job;
    public $busy = false;
    public function run(){
        //set busy = true
        $this->busy = true;
        //do job
        echo date('Y-m-d H:i:s')."�߳�����{$this->job}ִ�п�ʼ\n";
        sleep(5);
        echo date('Y-m-d H:i:s')."�߳�����{$this->job}ִ�н���\n";
        //set busy = false
        $this->busy = false;
    }
}

//script
$pool = new Threads(5,array(1,2,3,4,5,6,7,8,9,10,11));
while(1){
    if($pool->scan() == 'no jobs'){
        exit;
    }else{
        echo "���߳��ڽ��У�sleep 1 s\n";
        sleep(1);
    }
}

