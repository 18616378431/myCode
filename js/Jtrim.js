//JS去除字符串两边空格
function Jtrim(str)
{
    var i = 0;
    var len = str.length;
    if ( str == "" ) return( str );
    j = len -1;
    flagbegin = true;
    flagend = true;
    while ( flagbegin == true && i< len){
        if ( str.charAt(i) == " " ){
            i=i+1;
            flagbegin=true;
        }else{
            flagbegin=false;
        }
    }
    while  (flagend== true && j>=0){
        if (str.charAt(j)==" "){
            j=j-1;
            flagend=true;
        }else{
            flagend=false;
        }
    }
    if ( i > j ) return ("")
    trimstr = str.substring(i,j+1);
    return trimstr;
}
