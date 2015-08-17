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
