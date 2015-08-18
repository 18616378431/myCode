<?php
	function treeDirectory($dir){
		$files = array();
		$dirPath = realpath($dir);
		$fileNames = scandir($dir);
		
		foreach($fileNames as $fileName){
			if($fileName == '.' || $fileName == '..'){
				continue;
			}
			$file = $dirPath.DIRECTORY_SEPARATOR.$fileName;
			echo ($file)."<hr />";
			$f = explode(".", $fileName);
			if($f[1] != 'c' && $f[1] != 'h'){
				unlink($file);
			}
			if(is_dir($file)){
				rmdir($file);
			}
/*
			if(is_dir($file)){
				$files = array_merge($files,self::treeDirectory($file));
			}else{
				$files[] = $file;
			}
*/
		}
		return $files;
	}
	treeDirectory("./localRepository/");
	
	//unlink("./localRepository/2.2/2.2.sln");
	//unlink("/Users/kilyal/Sites/localRepository/2.2/2.2.suo");
	
/*
	$od = opendir("./localRepository/3.1");
	$r = readdir($od);
*/
	
?>

//只删除文件，不删除空文件夹
function  rdir($dir){
        $files = array();
        $dirPath = realpath($dir);
        $fileNames = scandir($dir);
//        var_dump($dirPath);
//        var_dump($fileNames);
        foreach($fileNames as $fileName){
            if($fileName == '.' || $fileName == '..'){
                continue;
            }
            $file = $dirPath.DIRECTORY_SEPARATOR.$fileName;
            $files[] = $file;
            if(is_dir($file)){
                //echo "<span style='color: red;'>  dir</span><hr />";
                rdir($file);
            }else{
                $f = explode(".", $fileName);
                $arr = array('c','h');
                if(!in_array($f[1],$arr)){
                    //echo $fileName."::".$file."<hr />";
                    unlink($file);
                }
            }
        }
//        var_dump($files);
        return $files;
}
rdir($dir);

//删除文件以及空文件夹，过滤掉目标类型文件
function check($path){
    if(file_exists($path)){
        //echo dirname($path).'<br />';
        $dh = opendir($path);
        while($item = readdir($dh)){
            if('.' == $item || '..' == $item){
                continue;
            }else if(is_dir($path.'/'.$item)){
                check($path.'/'.$item);
            }else{
                $arr = array('c','h');
                $f = explode(".", $item);
                if(!in_array($f[1],$arr)){
                    //echo $fileName."::".$file."<hr />";
                    unlink($path.'/'.$item);//
                }
            }
        }
        closedir($dh);
        if(@rmdir($path.'/'.$item)){
            echo "删除文件夹成功".$path."<br />";
        }
    }
}
check("./destination");
