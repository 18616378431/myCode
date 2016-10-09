<?php
function tail($fp, $n, $base = 5)
{
	assert($n > 0);
	$pos = $n + 1;
	$lines = array();
	while (count($lines) <= $n)
	{
		try
		{
			fseek($fp, -$pos, SEEK_END);
		}
		catch (Exception $e)
		{
			fseek(0);
			break;
		}
		$pos *= $base;
		while (!feof($fp))
		{
			array_unshift($lines, fgets($fp));
		}
	}
	return array_slice($lines, 0, $n);
}
var_dump(tail(fopen("access.log", "r+"), 10));





$fp = fopen($file, "r");
$line = 10;
$pos = -2;
$t = " ";
$data = "";
while ($line > 0)
{
 while ($t != "＼n")
 {
  fseek($fp, $pos, SEEK_END);
  $t = fgetc($fp);
  $pos--;
 }
 $t = " ";
 $data .= fgets($fp);
 $line--;
}
fclose($fp);
echo $data



/**
 * 取文件最后$n行
 * @param string $filename 文件路径
 * @param int $n 最后几行
 * @return mixed false表示有错误，成功则返回字符串
 */
function FileLastLines($filename,$n){
    if(!$fp=fopen($filename,'r')){
        echo "打开文件失败，请检查文件路径是否正确，路径和文件名不要包含中文";
        return false;
    }
    $pos=-2;
    $eof="";
    $str="";
    while($n>0){
        while($eof!="\n"){
            if(!fseek($fp,$pos,SEEK_END)){
                $eof=fgetc($fp);
                $pos--;
            }else{
                break;
            }
        }
        $str.=fgets($fp);
        $eof="";
        $n--;
    }
    return $str;
}
echo nl2br(FileLastLines('sss.txt',4));
?>