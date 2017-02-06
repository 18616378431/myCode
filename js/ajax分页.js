$(document).ready(function () { //本人习惯这样写了
    $(window).scroll(function () {
        //$(window).scrollTop()这个方法是当前滚动条滚动的距离
        //$(window).height()获取当前窗体的高度
        //$(document).height()获取当前文档的高度
        var bot = 50; //bot是底部距离的高度
        if ((bot + $(window).scrollTop()) >= ($(document).height() - $(window).height())) {
           //当底部基本距离+滚动的高度〉=文档的高度-窗体的高度时；
            //我们需要去异步加载数据了
            $.getJSON("url", { page: "2" }, function (str) { alert(str); });
        }
    });
});
===========================================================================================================
注意：(window).height()和(document).height()的区别
jQuery(window).height()代表了当前可见区域的大小，而jQuery(document).height()则代表了整个文档的高度，可视具体情况使用.
注意当浏览器窗口大小改变时(如最大化或拉大窗口后) jQuery(window).height() 随之改变，但是jQuery(document).height()是不变的。
复制代码 代码如下:
$(document).scrollTop() 获取垂直滚动的距离  即当前滚动的地方的窗口顶端到整个页面顶端的距离
$(document).scrollLeft() 这是获取水平滚动条的距离
要获取顶端 只需要获取到scrollTop()==0的时候  就是顶端了
要获取底端 只要获取scrollTop()>=$(document).height()-$(window).height()  就可以知道已经滚动到底端了
复制代码 代码如下:

$(document).height()  //是获取整个页面的高度
$(window).height()  //是获取当前 也就是你浏览器所能看到的页面的那部分的高度  这个大小在你缩放浏览器窗口大小时 会改变 与document是不一样的  根据英文应该也能理解吧

自己做个实验就知道了 
复制代码 代码如下:

$(document).scroll(function(){
    $("#lb").text($(document).scrollTop());
})
<span id="lb" style="top:100px;left:100px;position:fixed;"></span><!--一个固定的span标记 滚动时方便查看-->
