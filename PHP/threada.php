<?php
/**
 * Created by PhpStorm.
 * User: jiankang.wang
 * Date: 2016/10/21
 * Time: 17:34
 */
class vote extends Thread {

    public $res    = '';
    public $url    = array();
    public $name   = '';
    public $runing = false;
    public $lc     = false;
    public $param;

    public function __construct($name) {

        $this->res    = '����,��һ������.';
        $this->param    = 0;
        $this->lurl   = 0;
        $this->name   = $name;
        $this->runing = true;
        $this->lc     = false;
    }

    public function run() {
        while ($this->runing) {

            if ($this->param != 0) {
                $nt          = rand(1, 10);
                echo "�߳�[{$this->name}]�յ��������::{$this->param},��Ҫ{$nt}�봦������.\n";
                $this->res   = rand(100, 999);
                sleep($nt);
                $this->lurl = $this->param;
                $this->param   = '';
            } else {
                echo "�߳�[{$this->name}]�ȴ�����..\n";
            }
            sleep(1);
        }
    }

}

//���ﴴ���̳߳�.
$pool[] = new vote('a');
$pool[] = new vote('b');
$pool[] = new vote('c');

//���������߳�,ʹ�䴦�ڹ���״̬
foreach ($pool as $w) {
    $w->start();
}

//�ɷ�������߳�
for ($i = 1; $i < 10; $i++) {
    $worker_content = rand(10, 99);
    while (true) {
        foreach ($pool as $worker) {
            //����Ϊ����˵���߳̿���
            if ($worker->param=='') {
                $worker->param = $worker_content;
                echo "[{$worker->name}]�߳̿���,�������{$worker_content},�ϴβ���[{$worker->lurl}]���[{$worker->res}].\n";
                break 2;
            }
        }
        sleep(1);
    }
}
echo "�����߳��ɷ����,�ȴ�ִ�����.\n";

//�ȴ������߳����н���
while (count($pool)) {
    //��������߳������н���
    foreach ($pool as $key => $threads) {
        if ($threads->param=='') {
            echo "[{$threads->name}]�߳̿���,�ϴβ���[{$threads->lurl}]���[{$threads->res}].\n";
            echo "[{$threads->name}]�߳��������,�˳�.\n";
            //���ý�����־
            $threads->runing = false;
            unset($pool[$key]);
        }
    }
    echo "�ȴ���...\n";
    sleep(1);
}
echo "�����߳�ִ�����.\n";