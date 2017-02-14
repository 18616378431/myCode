<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
    <script src="../js/jquery-1.4.1.min.js" type="text/javascript"></script>
    <script>
        $(document).ready(function(){
            var num = "13966778888";
            var rs = num.substring(0,3)+"****"+num.substring(7,11);
            console.log(rs);
        });

    </script>
</head>
<body>
phone
<?php
$num = "13966778888";
echo $str = substr_replace($num,'****',3,4);

/**
 * 替换固定电话或手机号的中间四位
 * @param $phone
 * @return mixed
 */
function hidtel($phone){
    $IsWhat = preg_match('/(0[0-9]{2,3}[\-]?[2-9][0-9]{6,7}[\-]?[0-9]?)/i',$phone); //固定电话
    if($IsWhat == 1){
        return preg_replace('/(0[0-9]{2,3}[\-]?[2-9])[0-9]{3,4}([0-9]{3}[\-]?[0-9]?)/i','$1****$2',$phone);
    }else{
        return  preg_replace('/(1[358]{1}[0-9])[0-9]{4}([0-9]{4})/i','$1****$2',$phone);
    }
}
echo hidtel($num);
?>
</body>
</html>
