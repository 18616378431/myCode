<?php

class findFile{
    /**
    * 查询目录下的文件
    * $dir 目录全路径
    * $filterString  查询文件名的字符串，如果为空的话，返回目录所有文件
    * return:符合条件的文件
     */
    public function getFilenames( $dir,$filterString='',$scanChildDir = false )
    {
        $filenames = array();
        if ($dh = opendir($dir))
        {
            while ( ($file = readdir($dh)) !== false )
            {
                if( $file != '.' && $file != '..' )
                {
                    if( $scanChildDir && is_dir( $dir.'/'.$file ) )
                    {
                        $tmp = array();
                        $tmp = $this->getFilenames( $dir.'/'.$file, $filterString, $scanChildDir);
                        if( !empty($tmp) )
                        {
                            $filenames = array_merge( $filenames, $tmp );
                        }
                    }else if( !is_dir( $dir.'/'.$file ) )
                    {
                        if( $filterString !='' )
                        {
                            if( strpos($file,$filterString) !== false )
                            {
                                $filenames[]=$dir.'/'.$file;
                            }
                        }else
                        {
                            $filenames[]=$dir.'/'.$file;
                        }
                    }
                }
            }
            closedir($dh);
        }
        return $filenames;
    }
}
