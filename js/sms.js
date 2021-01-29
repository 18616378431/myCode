//短信验证码
var time = 60;
that = $("#smsbtn");
that.attr("disabled", true);
var timer = setInterval(function () {
	if (time == 0) {
		clearInterval(timer);
		that.attr("disabled", false);
		that.val("获取验证码");
	} else {
		that.val(time + "秒");
		time--;
	}
}, 1000);

$.ajax({
	url: "url",
	type: 'post',
	data: 'tel=' + $('#phone').val(),
	async: false,
	success: function (data) {
		if (data['code'] != 200) {
			alert(data['message']);
		}
	}
});