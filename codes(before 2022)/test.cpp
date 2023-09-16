<!DOCTYPE html>
<html lang="zh-cn">
	<head>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />
				<title>22冲刺day20-薰衣草 - 题目 - Zhengrui Online Judge</title>
		
		<script type="text/javascript">uojHome = 'http://zhengruioi.com'</script>

		<!-- Bootstrap core CSS -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap.min.css?v=2015.5.31" />		<!-- Bootstrap theme -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap-theme.min.css?v=2015.5.31" />
		<!-- Custom styles for this template -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/uoj-theme.css?v=2.33" />		
		<!-- jQuery (necessary for Bootstrap\'s JavaScript plugins) -->
		<script src="http://zhengruioi.com/js/jquery.min.js"></script>		
		<!-- jQuery autosize -->
		<script src="http://zhengruioi.com/js/jquery.autosize.min.js"></script>		<script type="text/javascript">
			$(document).ready(function() {
				$('textarea').autosize();
			});
		</script>
		
		<!-- jQuery cookie -->
		<script src="http://zhengruioi.com/js/jquery.cookie.min.js"></script>		
		<!-- jQuery modal -->
		<script src="http://zhengruioi.com/js/jquery.modal.js"></script>		
		<!-- jQuery tag canvas -->
				
		<!-- Include all compiled plugins (below), or include individual files as needed -->
		<script src="http://zhengruioi.com/js/bootstrap.min.js?v=2015.5.31"></script>		
		<!-- Color converter -->
		<script src="http://zhengruioi.com/js/color-converter.min.js"></script>		
		<!-- uoj -->
		<script src="http://zhengruioi.com/js/uoj.js?v=2016.8.15"></script>		
		<!-- LAB -->
		<script src="http://zhengruioi.com/js/LAB.min.js"></script>
		<!-- UOJ ico -->
		<link rel="shortcut icon" href="http://zhengruioi.com/pictures/UOJ.ico" />
		
				
				
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sweetalert.min.css" />		<script src="http://zhengruioi.com/js/sweetalert.min.js"></script>
				
				
				
				<!-- MathJax -->

        <script type="text/x-mathjax-config">
			MathJax.Hub.Config({
				showProcessingMessages: false,
				tex2jax: {
					inlineMath: [["$", "$"], ["\\\\(", "\\\\)"]],
					processEscapes:true
				},
				menuSettings: {
					zoom: "Hover"
    			}
			});
		</script>
<!--		<script src="//cdn.bootcss.com/mathjax/2.6.0/MathJax.js?config=TeX-AMS_HTML"></script>-->
        <script src="/js/MathJax-2.7.9/MathJax.js?config=TeX-AMS_HTML"></script>
        <!-- <script src="https://cdn.bootcdn.net/ajax/libs/mathjax/2.6.0/config/TeX-AMS_HTML-full.js"></script> -->
				
				<!-- jquery form -->
		<script src="http://zhengruioi.com/js/jquery.form.min.js"></script>				
		
				
				
				
				
				<!-- shjs -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sh_typical.min.css" />		<script src="http://zhengruioi.com/js/sh_main.min.js"></script>		<script type="text/javascript">$(document).ready(function(){sh_highlightDocument()})</script>
				
		
		<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
		<!--[if lt IE 9]>
			<script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
			<script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
		<![endif]-->
		
		<script type="text/javascript">
		before_window_unload_message = null;
		$(window).on('beforeunload', function() {
			if (before_window_unload_message !== null) {
			    return before_window_unload_message;
			}
		});
		</script>
		
			</head>
	<body role="document">
		<div class="container theme-showcase" role="main">
						<div>
				<ul class="nav nav-pills pull-right" role="tablist">
									<li class="dropdown">
						<a href="#" data-toggle="dropdown">
							<span class="uoj-username" data-rating="1503" data-link="0">Meko</span> 						</a>
						<ul class="dropdown-menu" role="menu">
							<li role="presentation"><a href="http://zhengruioi.com/user/msg">私信&nbsp;&nbsp;</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/profile/Meko">个人信息</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/system-msg">系统消息&nbsp;&nbsp;</a></li>
													</ul>
					</li>
					<li role="presentation"><a href="http://zhengruioi.com/logout?_token=qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy">登出</a></li>
								</ul>
				<h1 class="hidden-xs"><a href="http://zhengruioi.com"><img src="http://zhengruioi.com/pictures/UOJ_small.png" alt="UOJ Logo" class="img-rounded" style="width:39px; height:39px;" /></a> Zhengrui Online Judge</h1>
				<h1 class="visible-xs">ZROI</h1>
			</div>
			
			<div class="navbar navbar-default" role="navigation">
	<div class="container-fluid">
		<div class="navbar-header">
			<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".navbar-collapse">
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
			</button>
			<a class="navbar-brand" href="http://zhengruioi.com">ZROI</a>
		</div>
		<div class="navbar-collapse collapse">
			<ul class="nav navbar-nav">
				<li><a href="/contests">比赛</a></li>
				<li><a href="/problems">题库</a></li>
				<li><a href="/submissions">提交记录</a></li>
				<li><a href="/hacks">Hack!</a></li>
				<li><a href="/blogs">博客</a></li>
				<li><a href="/faq">帮助</a></li>
				<li><a href="/rollkings">卷王榜</a></li>
<!--                <li><a href="/rollkings">--><?//= UOJLocale::get('roll kings nav') ?><!--</a></li>-->
									<li><a data-target="#switchModal" href="#" data-toggle="modal">切换</a></li>
					<div class="modal fade in" id="switchModal" tabindex="-1" aria-labelledby="switchModalLabel" aria-hidden="true" style="display: none;">
						<div class="modal-dialog" style="width: 400px;">
							<div class="modal-content">
								<div class="modal-header" style="height: 51px;">
									<h4 class="modal-title" id="switchModalLabel" style="float:left">权限选择</h4>
									<button type="button" class="close" data-dismiss="modal" aria-label="Close" style="float:right">
									<span aria-hidden="true">×</span>
									</button>
								</div>
								<form name="switchChooseForm" method="post">
									<input type="hidden" name="switchChooseFormHiddenInput" id="switchChooseFormHiddenInput" value="switch">
									<div class="modal-body">
										<div class="table-responsive">
											<table class="table table-bordered table-hover table-striped table-text-center">
												<thead><tr>
													<th><label style="margin-bottom: 2px;">
														<input type="checkbox" style="vertical-align: middle;margin-top: 0px;" id="switchChooseAll"><span style="vertical-align: middle"> 全选</span>
													</label></th>
													<th style="vertical-align: middle">团队名称</th>
												</tr></thead>
												<tbody>
													<tr><td><input id="switchCheckbox86" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="86"></td><td>金华一中2022联赛训练</td></tr><tr><td><input id="switchCheckbox98" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="98"></td><td>22暑期CD集训</td></tr><tr><td><input id="switchCheckbox103" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="103"></td><td>22noip赛前20天</td></tr>													
												</tbody>
											</table>
										</div>
									</div>
									<div class="modal-footer">
										<button type="button" class="btn btn-secondary" data-dismiss="modal">取消</button>
										<button type="submit" class="btn btn-primary">确认</button>
									</div>
								</form>
								<script type="text/javascript">
									$("#switchChooseAll").click(function() {
										if (this.checked) {
											$("#switchCheckbox86").prop("checked", true);$("#switchCheckbox98").prop("checked", true);$("#switchCheckbox103").prop("checked", true);										} else {
											$("#switchCheckbox86").prop("checked", false);$("#switchCheckbox98").prop("checked", false);$("#switchCheckbox103").prop("checked", false);										}
									})
								</script>
							</div>
						</div>
					</div>
							</ul>
		</div><!--/.nav-collapse -->
	</div>
</div>
<script type="text/javascript">
function swalConfirm(text) {
	return swal({
		html : text,
		type : 'warning',
		showCancelButton : true,
		allowOutsideClick : false,
		confirmButtonText : 'Yes',
		cancelButtonText : 'No',
		focusCancel : true
	});
}

function switchTo(id) {
	swalConfirm('您确定要切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 吗？')
	.then(function() {
		$.post('/', {
			id : id,
			type : 'switch'
		}, function(msg) {
			if (msg == 'ok') {
				swal('', '成功切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 啦', 'success')
				.then(function() {
					window.location.reload();
				});
			} else swal('', '切换失败，如有疑问请联系蔡老师', 'error');
		});
	});
}
</script>
						
			<div class="uoj-content">
<script src="/js/sec.min.js"></script><script>__canvasWM({content: 'qbYCXKLlZmD5j5oAWdfpC0pWbYnud1VGtdKRoIp3SPI='});</script>
<h1 class="page-header text-center" style="margin-bottom:0px;border-bottom:0px">#2433. 22冲刺day20-薰衣草</h1>
<div class="row" style="margin-bottom:20px;border-bottom:1px">
	<div class="col-sm-2"></div>
	<div class="col-sm-8 text-center">
					<div class="btn-group" role="group" aria-label="First group">
				<button type="button" class="uoj-tag btn" disabled="">时间限制：2000 ms</button>
				<button type="button" class="uoj-tag btn" disabled="">空间限制：1024 MiB</button>
				<button type="button" class="uoj-tag btn" disabled="">题目类型：传统型</button>
				<button type="button" class="uoj-tag btn" disabled="">答案检查器：文本比较</button>
			</div>
			</div>
	<div class="col-sm-2 text-right">
		<div class="uoj-click-zan-block" data-id="2433" data-type="P" data-val="0" data-cnt="-30"></div>	</div>
</div>
<a role="button" class="btn btn-info pull-right" href="/problem/2433/statistics"><span class="glyphicon glyphicon-stats"></span> 统计</a>
	<a role="button" class="btn btn-info pull-right" href="/download.php?type=tutorial&id=2433" style="margin-right: 5px"><span class="glyphicon glyphicon-file"></span> 题解</a>

<ul class="nav nav-tabs" role="tablist">
	<li class="active"><a href="#tab-statement" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-book"></span> 描述</a></li>
	<li><a href="#tab-submit-answer" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-upload"></span> 提交</a></li>
		<li><a href="#tab-custom-test" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-console"></span> 自定义测试</a></li>
			<li><a href="/download.php?type=problem&id=2433" role="button"><span class="glyphicon glyphicon-download"></span> 下发文件下载</a></li>
			</ul>
<div class="tab-content">
	<div class="tab-pane active" id="tab-statement">
				<article class="top-buffer-md"><h4>题目描述</h4>
<p>花花和啾啾是好朋友，有一天他们在玩游戏，规则是：</p>
<ol><li>花花先手，啾啾后手，轮流进行操作，共有$m$ 轮操作，有一个集合初始为$S=\{a_1,a_2,\cdots,a_n\}$。</li>
<li>第 $i$ 轮操作有一个参数 $b_i$，当前轮的操作者有以下两个选择：保留 $S$ 中所有是 $b_i$ 倍数的数字，或者保留 $S$ 中所有不是 $b_i$ 倍数的数字。</li>
<li>进行了 $m$ 轮操作后两人获得的权值是 $S$ 中的数字之和，$S$ 可以为空。</li>
</ol><p>花花希望权值最小，啾啾希望权值最大，假设他们足够聪明，那么游戏最终的权值是多少。</p>
<h4>输入格式</h4>
<p>第一行两个整数 $n,m$，表示集合大小和操作轮数。</p>
<p>第二行 $n$ 个整数 $a_i$，表示初始集合。</p>
<p>第三行 $m$ 个整数 $b_i$，为第 $i$ 轮的参数。</p>
<h4>输出格式</h4>
<p>输出一个数表示博弈的结果。</p>
<h4>样例输入1</h4>
<pre><code>10 3
13 -6 -9 -8 11 5 -4 -9 -4  -7
2 3 3</code></pre>
<h4>样例输出1</h4>
<pre><code>-6</code></pre>
<h4>样例2</h4>
<p>见下发文件</p>
<h4>数据范围</h4>
<p>对于$100\%$的数据，$1\le n\le2\times 10^4, 1\le m \le 2\times 10^5, -4\times 10^{14} \le a_i \le 4\times 10^{14}, 1\le b_i \le 4\times 10^{14}$。</p>
<div class="table-responsive">
<table class="table table-bordered table-text-center table-vertical-middle"><thead><tr><th align="center">子任务编号</th>
<th align="center">$m\le$</th>
<th align="center">特殊性质</th>
<th align="center">分数</th>
</tr></thead><tbody><tr><td align="center">1</td>
<td align="center">1</td>
<td align="center"></td>
<td align="center">3</td>
</tr><tr><td align="center">2</td>
<td align="center">$2\times 10^5$</td>
<td align="center">$\forall i &lt; m, b_i=b_{i+1}$</td>
<td align="center">6</td>
</tr><tr><td align="center">3</td>
<td align="center">$2\times 10^5$</td>
<td align="center">$\forall i &lt; m, b_{i+1} \bmod b_i =0$</td>
<td align="center">15</td>
</tr><tr><td align="center">4</td>
<td align="center">7</td>
<td align="center"></td>
<td align="center">9</td>
</tr><tr><td align="center">5</td>
<td align="center">20</td>
<td align="center"></td>
<td align="center">11</td>
</tr><tr><td align="center">6</td>
<td align="center">100</td>
<td align="center"></td>
<td align="center">15</td>
</tr><tr><td align="center">7</td>
<td align="center">$2\times 10^5$</td>
<td align="center">$m \bmod 2=0, \forall i \le \frac{m}{2}, b_{2i-1}=b_{2i}$</td>
<td align="center">11</td>
</tr><tr><td align="center">8</td>
<td align="center">$2\times 10^5$</td>
<td align="center"></td>
<td align="center">30</td>
</tr></tbody></table></div>
</article>
	</div>
	<div class="tab-pane" id="tab-submit-answer">
		<div class="top-buffer-sm"></div>
				<form action="/problem/2433" method="post" class="form-horizontal" id="form-answer" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-answer_answer"></div>
<script type="text/javascript">
$('#form-group-answer_answer').source_code_form_group('answer_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="text-center"><button type="submit" id="button-submit-answer" name="submit-answer" value="answer" class="btn btn-default">提交</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-answer').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-answer'] = "";
			$.ajax({
				url : '/problem/2433',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		return ok;
	});
});
</script>	</div>
		<div class="tab-pane" id="tab-custom-test">
		<div class="top-buffer-sm"></div>
		<form action="/problem/2433" method="post" class="form-horizontal" id="form-custom_test" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-custom_test_answer"></div>
<script type="text/javascript">
$('#form-group-custom_test_answer').source_code_form_group('custom_test_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="form-group" id="form-group-custom_test_input"></div>
<script type="text/javascript">
$('#form-group-custom_test_input').text_file_form_group('custom_test_input', '文本文件:input.txt');
</script><div id="div-custom_test_result"></div><div class="text-center"><button type="submit" id="button-submit-custom_test" name="submit-custom_test" value="custom_test" class="btn btn-default">运行</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-custom_test').keydown(function(e) {
		if (e.keyCode == 13 && e.ctrlKey) {
			$('#button-submit-custom_test').click();
		}
	});
	$('#form-custom_test').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-custom_test'] = "";
			$.ajax({
				url : '/problem/2433',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		e.preventDefault();
		if (ok) {
			$(this).ajaxSubmit({
				beforeSubmit: function(formData) {
					formData.push({name: 'submit-custom_test', value: 'custom_test', type: 'submit'});
				},
				success : function(response_text) {custom_test_onsubmit(response_text, $('#div-custom_test_result')[0], '/problem/2433?get=custom-test-status-details')}
			});
		}
	});
});
</script>	</div>
	</div>
			</div>
						<div class="uoj-footer">
				<p>
					<a href="http://zhengruioi.com/problem/2433?locale=zh-cn"><img src="/pictures/lang/cn.png" alt="中文" /></a> 
					<a href="http://zhengruioi.com/problem/2433?locale=en"><img src="/pictures/lang/gb.png" alt="English" /></a>
				</p>
				
				<ul class="list-inline">
					<li>Zhengrui Online Judge</li>
									</ul>
				
				<p>Server time: 2022-11-17 11:38:24 &nbsp; | &nbsp;  <a href="http://www.beian.miit.gov.cn/">浙ICP备17047493号</a></p>
			</div>
					</div>
		<!-- /container -->
	</body>
</html>
<!DOCTYPE html>
<html lang="zh-cn">
	<head>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />
				<title>22冲刺day20-风信子 - 题目 - Zhengrui Online Judge</title>
		
		<script type="text/javascript">uojHome = 'http://zhengruioi.com'</script>

		<!-- Bootstrap core CSS -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap.min.css?v=2015.5.31" />		<!-- Bootstrap theme -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap-theme.min.css?v=2015.5.31" />
		<!-- Custom styles for this template -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/uoj-theme.css?v=2.33" />		
		<!-- jQuery (necessary for Bootstrap\'s JavaScript plugins) -->
		<script src="http://zhengruioi.com/js/jquery.min.js"></script>		
		<!-- jQuery autosize -->
		<script src="http://zhengruioi.com/js/jquery.autosize.min.js"></script>		<script type="text/javascript">
			$(document).ready(function() {
				$('textarea').autosize();
			});
		</script>
		
		<!-- jQuery cookie -->
		<script src="http://zhengruioi.com/js/jquery.cookie.min.js"></script>		
		<!-- jQuery modal -->
		<script src="http://zhengruioi.com/js/jquery.modal.js"></script>		
		<!-- jQuery tag canvas -->
				
		<!-- Include all compiled plugins (below), or include individual files as needed -->
		<script src="http://zhengruioi.com/js/bootstrap.min.js?v=2015.5.31"></script>		
		<!-- Color converter -->
		<script src="http://zhengruioi.com/js/color-converter.min.js"></script>		
		<!-- uoj -->
		<script src="http://zhengruioi.com/js/uoj.js?v=2016.8.15"></script>		
		<!-- LAB -->
		<script src="http://zhengruioi.com/js/LAB.min.js"></script>
		<!-- UOJ ico -->
		<link rel="shortcut icon" href="http://zhengruioi.com/pictures/UOJ.ico" />
		
				
				
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sweetalert.min.css" />		<script src="http://zhengruioi.com/js/sweetalert.min.js"></script>
				
				
				
				<!-- MathJax -->

        <script type="text/x-mathjax-config">
			MathJax.Hub.Config({
				showProcessingMessages: false,
				tex2jax: {
					inlineMath: [["$", "$"], ["\\\\(", "\\\\)"]],
					processEscapes:true
				},
				menuSettings: {
					zoom: "Hover"
    			}
			});
		</script>
<!--		<script src="//cdn.bootcss.com/mathjax/2.6.0/MathJax.js?config=TeX-AMS_HTML"></script>-->
        <script src="/js/MathJax-2.7.9/MathJax.js?config=TeX-AMS_HTML"></script>
        <!-- <script src="https://cdn.bootcdn.net/ajax/libs/mathjax/2.6.0/config/TeX-AMS_HTML-full.js"></script> -->
				
				<!-- jquery form -->
		<script src="http://zhengruioi.com/js/jquery.form.min.js"></script>				
		
				
				
				
				
				<!-- shjs -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sh_typical.min.css" />		<script src="http://zhengruioi.com/js/sh_main.min.js"></script>		<script type="text/javascript">$(document).ready(function(){sh_highlightDocument()})</script>
				
		
		<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
		<!--[if lt IE 9]>
			<script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
			<script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
		<![endif]-->
		
		<script type="text/javascript">
		before_window_unload_message = null;
		$(window).on('beforeunload', function() {
			if (before_window_unload_message !== null) {
			    return before_window_unload_message;
			}
		});
		</script>
		
			</head>
	<body role="document">
		<div class="container theme-showcase" role="main">
						<div>
				<ul class="nav nav-pills pull-right" role="tablist">
									<li class="dropdown">
						<a href="#" data-toggle="dropdown">
							<span class="uoj-username" data-rating="1503" data-link="0">Meko</span> 						</a>
						<ul class="dropdown-menu" role="menu">
							<li role="presentation"><a href="http://zhengruioi.com/user/msg">私信&nbsp;&nbsp;</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/profile/Meko">个人信息</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/system-msg">系统消息&nbsp;&nbsp;</a></li>
													</ul>
					</li>
					<li role="presentation"><a href="http://zhengruioi.com/logout?_token=qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy">登出</a></li>
								</ul>
				<h1 class="hidden-xs"><a href="http://zhengruioi.com"><img src="http://zhengruioi.com/pictures/UOJ_small.png" alt="UOJ Logo" class="img-rounded" style="width:39px; height:39px;" /></a> Zhengrui Online Judge</h1>
				<h1 class="visible-xs">ZROI</h1>
			</div>
			
			<div class="navbar navbar-default" role="navigation">
	<div class="container-fluid">
		<div class="navbar-header">
			<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".navbar-collapse">
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
			</button>
			<a class="navbar-brand" href="http://zhengruioi.com">ZROI</a>
		</div>
		<div class="navbar-collapse collapse">
			<ul class="nav navbar-nav">
				<li><a href="/contests">比赛</a></li>
				<li><a href="/problems">题库</a></li>
				<li><a href="/submissions">提交记录</a></li>
				<li><a href="/hacks">Hack!</a></li>
				<li><a href="/blogs">博客</a></li>
				<li><a href="/faq">帮助</a></li>
				<li><a href="/rollkings">卷王榜</a></li>
<!--                <li><a href="/rollkings">--><?//= UOJLocale::get('roll kings nav') ?><!--</a></li>-->
									<li><a data-target="#switchModal" href="#" data-toggle="modal">切换</a></li>
					<div class="modal fade in" id="switchModal" tabindex="-1" aria-labelledby="switchModalLabel" aria-hidden="true" style="display: none;">
						<div class="modal-dialog" style="width: 400px;">
							<div class="modal-content">
								<div class="modal-header" style="height: 51px;">
									<h4 class="modal-title" id="switchModalLabel" style="float:left">权限选择</h4>
									<button type="button" class="close" data-dismiss="modal" aria-label="Close" style="float:right">
									<span aria-hidden="true">×</span>
									</button>
								</div>
								<form name="switchChooseForm" method="post">
									<input type="hidden" name="switchChooseFormHiddenInput" id="switchChooseFormHiddenInput" value="switch">
									<div class="modal-body">
										<div class="table-responsive">
											<table class="table table-bordered table-hover table-striped table-text-center">
												<thead><tr>
													<th><label style="margin-bottom: 2px;">
														<input type="checkbox" style="vertical-align: middle;margin-top: 0px;" id="switchChooseAll"><span style="vertical-align: middle"> 全选</span>
													</label></th>
													<th style="vertical-align: middle">团队名称</th>
												</tr></thead>
												<tbody>
													<tr><td><input id="switchCheckbox86" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="86"></td><td>金华一中2022联赛训练</td></tr><tr><td><input id="switchCheckbox98" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="98"></td><td>22暑期CD集训</td></tr><tr><td><input id="switchCheckbox103" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="103"></td><td>22noip赛前20天</td></tr>													
												</tbody>
											</table>
										</div>
									</div>
									<div class="modal-footer">
										<button type="button" class="btn btn-secondary" data-dismiss="modal">取消</button>
										<button type="submit" class="btn btn-primary">确认</button>
									</div>
								</form>
								<script type="text/javascript">
									$("#switchChooseAll").click(function() {
										if (this.checked) {
											$("#switchCheckbox86").prop("checked", true);$("#switchCheckbox98").prop("checked", true);$("#switchCheckbox103").prop("checked", true);										} else {
											$("#switchCheckbox86").prop("checked", false);$("#switchCheckbox98").prop("checked", false);$("#switchCheckbox103").prop("checked", false);										}
									})
								</script>
							</div>
						</div>
					</div>
							</ul>
		</div><!--/.nav-collapse -->
	</div>
</div>
<script type="text/javascript">
function swalConfirm(text) {
	return swal({
		html : text,
		type : 'warning',
		showCancelButton : true,
		allowOutsideClick : false,
		confirmButtonText : 'Yes',
		cancelButtonText : 'No',
		focusCancel : true
	});
}

function switchTo(id) {
	swalConfirm('您确定要切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 吗？')
	.then(function() {
		$.post('/', {
			id : id,
			type : 'switch'
		}, function(msg) {
			if (msg == 'ok') {
				swal('', '成功切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 啦', 'success')
				.then(function() {
					window.location.reload();
				});
			} else swal('', '切换失败，如有疑问请联系蔡老师', 'error');
		});
	});
}
</script>
						
			<div class="uoj-content">
<script src="/js/sec.min.js"></script><script>__canvasWM({content: 'qbYCXKLlZmD5j5oAWdfpC0pWbYnud1VGtdKRoIp3SPI='});</script>
<h1 class="page-header text-center" style="margin-bottom:0px;border-bottom:0px">#2434. 22冲刺day20-风信子</h1>
<div class="row" style="margin-bottom:20px;border-bottom:1px">
	<div class="col-sm-2"></div>
	<div class="col-sm-8 text-center">
					<div class="btn-group" role="group" aria-label="First group">
				<button type="button" class="uoj-tag btn" disabled="">时间限制：2000 ms</button>
				<button type="button" class="uoj-tag btn" disabled="">空间限制：1024 MiB</button>
				<button type="button" class="uoj-tag btn" disabled="">题目类型：传统型</button>
				<button type="button" class="uoj-tag btn" disabled="">答案检查器：文本比较</button>
			</div>
			</div>
	<div class="col-sm-2 text-right">
		<div class="uoj-click-zan-block" data-id="2434" data-type="P" data-val="0" data-cnt="-16"></div>	</div>
</div>
<a role="button" class="btn btn-info pull-right" href="/problem/2434/statistics"><span class="glyphicon glyphicon-stats"></span> 统计</a>
	<a role="button" class="btn btn-info pull-right" href="/download.php?type=tutorial&id=2434" style="margin-right: 5px"><span class="glyphicon glyphicon-file"></span> 题解</a>

<ul class="nav nav-tabs" role="tablist">
	<li class="active"><a href="#tab-statement" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-book"></span> 描述</a></li>
	<li><a href="#tab-submit-answer" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-upload"></span> 提交</a></li>
		<li><a href="#tab-custom-test" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-console"></span> 自定义测试</a></li>
			<li><a href="/download.php?type=problem&id=2434" role="button"><span class="glyphicon glyphicon-download"></span> 下发文件下载</a></li>
			</ul>
<div class="tab-content">
	<div class="tab-pane active" id="tab-statement">
				<article class="top-buffer-md"><h4>题目描述</h4>
<p>花花和啾啾是好朋友，游戏输掉的花花必须解决这个问题才能收获啾啾的奖品：</p>
<p>求下图的最大流：源点为 $S$，汇点为 $T$，包括源汇总共 $n+2$ 个点。$S$ 向 $i$ 连边，流量为 $a_i$；$i$ 向 $T$ 连边，流量为 $b_i$；$i$ 向 $p_i$ 连边，流量为 $c_i$。</p>
<p>保证 $p_i\not = i$。</p>
<h4>输入格式</h4>
<p>第一行一个整数 $n$，表示除了源汇的节点个数。</p>
<p>第二行 $n$ 个整数 $p_i$，表示每个点的出边。</p>
<p>第三行 $n$ 个整数 $a_i$，表示源点到每个点的流量。</p>
<p>第四行 $n$ 个整数 $b_i$，表示每个点到汇点的流量。</p>
<p>第五行 $n$ 个整数 $c_i$，表示 $i$ 到 $p_i$ 的流量。</p>
<h4>输出格式</h4>
<p>输出一个数表示最大流。</p>
<h4>样例输入1</h4>
<pre><code>5
3 3 1 3 3
4 2 2 5 5
2 4 2 1 2
2 3 2 2 4</code></pre>
<h4>样例输出1</h4>
<pre><code>9</code></pre>
<h4>样例2，3</h4>
<p>见下发文件。</p>
<h4>数据范围</h4>
<p>对于$100\%$的数据，$2\le n \le 10^6, 1\le p_i \le n, 1\le a_i,b_i,c_i \le 10^9$。</p>
<div class="table-responsive">
<table class="table table-bordered table-text-center table-vertical-middle"><thead><tr><th align="center">子任务编号</th>
<th align="center">$n\le$</th>
<th align="center">特殊性质</th>
<th align="center">分数</th>
</tr></thead><tbody><tr><td align="center">1</td>
<td align="center">$20$</td>
<td align="center"></td>
<td align="center">13</td>
</tr><tr><td align="center">2</td>
<td align="center">$500$</td>
<td align="center"></td>
<td align="center">11</td>
</tr><tr><td align="center">3</td>
<td align="center">$5000$</td>
<td align="center"></td>
<td align="center">17</td>
</tr><tr><td align="center">4</td>
<td align="center">$10^5$</td>
<td align="center"></td>
<td align="center">26</td>
</tr><tr><td align="center">5</td>
<td align="center">$5\times 10^5$</td>
<td align="center">保证对于$i&gt;1$,$p_i$ 从 $1$ 到 $i-1$ 中随机</td>
<td align="center">17</td>
</tr><tr><td align="center">6</td>
<td align="center">$10^6$</td>
<td align="center"></td>
<td align="center">16</td>
</tr></tbody></table></div>
</article>
	</div>
	<div class="tab-pane" id="tab-submit-answer">
		<div class="top-buffer-sm"></div>
				<form action="/problem/2434" method="post" class="form-horizontal" id="form-answer" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-answer_answer"></div>
<script type="text/javascript">
$('#form-group-answer_answer').source_code_form_group('answer_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="text-center"><button type="submit" id="button-submit-answer" name="submit-answer" value="answer" class="btn btn-default">提交</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-answer').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-answer'] = "";
			$.ajax({
				url : '/problem/2434',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		return ok;
	});
});
</script>	</div>
		<div class="tab-pane" id="tab-custom-test">
		<div class="top-buffer-sm"></div>
		<form action="/problem/2434" method="post" class="form-horizontal" id="form-custom_test" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-custom_test_answer"></div>
<script type="text/javascript">
$('#form-group-custom_test_answer').source_code_form_group('custom_test_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="form-group" id="form-group-custom_test_input"></div>
<script type="text/javascript">
$('#form-group-custom_test_input').text_file_form_group('custom_test_input', '文本文件:input.txt');
</script><div id="div-custom_test_result"></div><div class="text-center"><button type="submit" id="button-submit-custom_test" name="submit-custom_test" value="custom_test" class="btn btn-default">运行</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-custom_test').keydown(function(e) {
		if (e.keyCode == 13 && e.ctrlKey) {
			$('#button-submit-custom_test').click();
		}
	});
	$('#form-custom_test').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-custom_test'] = "";
			$.ajax({
				url : '/problem/2434',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		e.preventDefault();
		if (ok) {
			$(this).ajaxSubmit({
				beforeSubmit: function(formData) {
					formData.push({name: 'submit-custom_test', value: 'custom_test', type: 'submit'});
				},
				success : function(response_text) {custom_test_onsubmit(response_text, $('#div-custom_test_result')[0], '/problem/2434?get=custom-test-status-details')}
			});
		}
	});
});
</script>	</div>
	</div>
			</div>
						<div class="uoj-footer">
				<p>
					<a href="http://zhengruioi.com/problem/2434?locale=zh-cn"><img src="/pictures/lang/cn.png" alt="中文" /></a> 
					<a href="http://zhengruioi.com/problem/2434?locale=en"><img src="/pictures/lang/gb.png" alt="English" /></a>
				</p>
				
				<ul class="list-inline">
					<li>Zhengrui Online Judge</li>
									</ul>
				
				<p>Server time: 2022-11-17 11:38:24 &nbsp; | &nbsp;  <a href="http://www.beian.miit.gov.cn/">浙ICP备17047493号</a></p>
			</div>
					</div>
		<!-- /container -->
	</body>
</html>
<!DOCTYPE html>
<html lang="zh-cn">
	<head>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />
				<title>22冲刺day20-栀子花 - 题目 - Zhengrui Online Judge</title>
		
		<script type="text/javascript">uojHome = 'http://zhengruioi.com'</script>

		<!-- Bootstrap core CSS -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap.min.css?v=2015.5.31" />		<!-- Bootstrap theme -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap-theme.min.css?v=2015.5.31" />
		<!-- Custom styles for this template -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/uoj-theme.css?v=2.33" />		
		<!-- jQuery (necessary for Bootstrap\'s JavaScript plugins) -->
		<script src="http://zhengruioi.com/js/jquery.min.js"></script>		
		<!-- jQuery autosize -->
		<script src="http://zhengruioi.com/js/jquery.autosize.min.js"></script>		<script type="text/javascript">
			$(document).ready(function() {
				$('textarea').autosize();
			});
		</script>
		
		<!-- jQuery cookie -->
		<script src="http://zhengruioi.com/js/jquery.cookie.min.js"></script>		
		<!-- jQuery modal -->
		<script src="http://zhengruioi.com/js/jquery.modal.js"></script>		
		<!-- jQuery tag canvas -->
				
		<!-- Include all compiled plugins (below), or include individual files as needed -->
		<script src="http://zhengruioi.com/js/bootstrap.min.js?v=2015.5.31"></script>		
		<!-- Color converter -->
		<script src="http://zhengruioi.com/js/color-converter.min.js"></script>		
		<!-- uoj -->
		<script src="http://zhengruioi.com/js/uoj.js?v=2016.8.15"></script>		
		<!-- LAB -->
		<script src="http://zhengruioi.com/js/LAB.min.js"></script>
		<!-- UOJ ico -->
		<link rel="shortcut icon" href="http://zhengruioi.com/pictures/UOJ.ico" />
		
				
				
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sweetalert.min.css" />		<script src="http://zhengruioi.com/js/sweetalert.min.js"></script>
				
				
				
				<!-- MathJax -->

        <script type="text/x-mathjax-config">
			MathJax.Hub.Config({
				showProcessingMessages: false,
				tex2jax: {
					inlineMath: [["$", "$"], ["\\\\(", "\\\\)"]],
					processEscapes:true
				},
				menuSettings: {
					zoom: "Hover"
    			}
			});
		</script>
<!--		<script src="//cdn.bootcss.com/mathjax/2.6.0/MathJax.js?config=TeX-AMS_HTML"></script>-->
        <script src="/js/MathJax-2.7.9/MathJax.js?config=TeX-AMS_HTML"></script>
        <!-- <script src="https://cdn.bootcdn.net/ajax/libs/mathjax/2.6.0/config/TeX-AMS_HTML-full.js"></script> -->
				
				<!-- jquery form -->
		<script src="http://zhengruioi.com/js/jquery.form.min.js"></script>				
		
				
				
				
				
				<!-- shjs -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sh_typical.min.css" />		<script src="http://zhengruioi.com/js/sh_main.min.js"></script>		<script type="text/javascript">$(document).ready(function(){sh_highlightDocument()})</script>
				
		
		<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
		<!--[if lt IE 9]>
			<script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
			<script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
		<![endif]-->
		
		<script type="text/javascript">
		before_window_unload_message = null;
		$(window).on('beforeunload', function() {
			if (before_window_unload_message !== null) {
			    return before_window_unload_message;
			}
		});
		</script>
		
			</head>
	<body role="document">
		<div class="container theme-showcase" role="main">
						<div>
				<ul class="nav nav-pills pull-right" role="tablist">
									<li class="dropdown">
						<a href="#" data-toggle="dropdown">
							<span class="uoj-username" data-rating="1503" data-link="0">Meko</span> 						</a>
						<ul class="dropdown-menu" role="menu">
							<li role="presentation"><a href="http://zhengruioi.com/user/msg">私信&nbsp;&nbsp;</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/profile/Meko">个人信息</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/system-msg">系统消息&nbsp;&nbsp;</a></li>
													</ul>
					</li>
					<li role="presentation"><a href="http://zhengruioi.com/logout?_token=qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy">登出</a></li>
								</ul>
				<h1 class="hidden-xs"><a href="http://zhengruioi.com"><img src="http://zhengruioi.com/pictures/UOJ_small.png" alt="UOJ Logo" class="img-rounded" style="width:39px; height:39px;" /></a> Zhengrui Online Judge</h1>
				<h1 class="visible-xs">ZROI</h1>
			</div>
			
			<div class="navbar navbar-default" role="navigation">
	<div class="container-fluid">
		<div class="navbar-header">
			<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".navbar-collapse">
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
			</button>
			<a class="navbar-brand" href="http://zhengruioi.com">ZROI</a>
		</div>
		<div class="navbar-collapse collapse">
			<ul class="nav navbar-nav">
				<li><a href="/contests">比赛</a></li>
				<li><a href="/problems">题库</a></li>
				<li><a href="/submissions">提交记录</a></li>
				<li><a href="/hacks">Hack!</a></li>
				<li><a href="/blogs">博客</a></li>
				<li><a href="/faq">帮助</a></li>
				<li><a href="/rollkings">卷王榜</a></li>
<!--                <li><a href="/rollkings">--><?//= UOJLocale::get('roll kings nav') ?><!--</a></li>-->
									<li><a data-target="#switchModal" href="#" data-toggle="modal">切换</a></li>
					<div class="modal fade in" id="switchModal" tabindex="-1" aria-labelledby="switchModalLabel" aria-hidden="true" style="display: none;">
						<div class="modal-dialog" style="width: 400px;">
							<div class="modal-content">
								<div class="modal-header" style="height: 51px;">
									<h4 class="modal-title" id="switchModalLabel" style="float:left">权限选择</h4>
									<button type="button" class="close" data-dismiss="modal" aria-label="Close" style="float:right">
									<span aria-hidden="true">×</span>
									</button>
								</div>
								<form name="switchChooseForm" method="post">
									<input type="hidden" name="switchChooseFormHiddenInput" id="switchChooseFormHiddenInput" value="switch">
									<div class="modal-body">
										<div class="table-responsive">
											<table class="table table-bordered table-hover table-striped table-text-center">
												<thead><tr>
													<th><label style="margin-bottom: 2px;">
														<input type="checkbox" style="vertical-align: middle;margin-top: 0px;" id="switchChooseAll"><span style="vertical-align: middle"> 全选</span>
													</label></th>
													<th style="vertical-align: middle">团队名称</th>
												</tr></thead>
												<tbody>
													<tr><td><input id="switchCheckbox86" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="86"></td><td>金华一中2022联赛训练</td></tr><tr><td><input id="switchCheckbox98" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="98"></td><td>22暑期CD集训</td></tr><tr><td><input id="switchCheckbox103" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="103"></td><td>22noip赛前20天</td></tr>													
												</tbody>
											</table>
										</div>
									</div>
									<div class="modal-footer">
										<button type="button" class="btn btn-secondary" data-dismiss="modal">取消</button>
										<button type="submit" class="btn btn-primary">确认</button>
									</div>
								</form>
								<script type="text/javascript">
									$("#switchChooseAll").click(function() {
										if (this.checked) {
											$("#switchCheckbox86").prop("checked", true);$("#switchCheckbox98").prop("checked", true);$("#switchCheckbox103").prop("checked", true);										} else {
											$("#switchCheckbox86").prop("checked", false);$("#switchCheckbox98").prop("checked", false);$("#switchCheckbox103").prop("checked", false);										}
									})
								</script>
							</div>
						</div>
					</div>
							</ul>
		</div><!--/.nav-collapse -->
	</div>
</div>
<script type="text/javascript">
function swalConfirm(text) {
	return swal({
		html : text,
		type : 'warning',
		showCancelButton : true,
		allowOutsideClick : false,
		confirmButtonText : 'Yes',
		cancelButtonText : 'No',
		focusCancel : true
	});
}

function switchTo(id) {
	swalConfirm('您确定要切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 吗？')
	.then(function() {
		$.post('/', {
			id : id,
			type : 'switch'
		}, function(msg) {
			if (msg == 'ok') {
				swal('', '成功切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 啦', 'success')
				.then(function() {
					window.location.reload();
				});
			} else swal('', '切换失败，如有疑问请联系蔡老师', 'error');
		});
	});
}
</script>
						
			<div class="uoj-content">
<script src="/js/sec.min.js"></script><script>__canvasWM({content: 'qbYCXKLlZmD5j5oAWdfpCzAeG7f+FK89R8q+o2NnAEU='});</script>
<h1 class="page-header text-center" style="margin-bottom:0px;border-bottom:0px">#2435. 22冲刺day20-栀子花</h1>
<div class="row" style="margin-bottom:20px;border-bottom:1px">
	<div class="col-sm-2"></div>
	<div class="col-sm-8 text-center">
					<div class="btn-group" role="group" aria-label="First group">
				<button type="button" class="uoj-tag btn" disabled="">时间限制：2000 ms</button>
				<button type="button" class="uoj-tag btn" disabled="">空间限制：1024 MiB</button>
				<button type="button" class="uoj-tag btn" disabled="">题目类型：传统型</button>
				<button type="button" class="uoj-tag btn" disabled="">答案检查器：文本比较</button>
			</div>
			</div>
	<div class="col-sm-2 text-right">
		<div class="uoj-click-zan-block" data-id="2435" data-type="P" data-val="0" data-cnt="-15"></div>	</div>
</div>
<a role="button" class="btn btn-info pull-right" href="/problem/2435/statistics"><span class="glyphicon glyphicon-stats"></span> 统计</a>
	<a role="button" class="btn btn-info pull-right" href="/download.php?type=tutorial&id=2435" style="margin-right: 5px"><span class="glyphicon glyphicon-file"></span> 题解</a>

<ul class="nav nav-tabs" role="tablist">
	<li class="active"><a href="#tab-statement" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-book"></span> 描述</a></li>
	<li><a href="#tab-submit-answer" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-upload"></span> 提交</a></li>
		<li><a href="#tab-custom-test" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-console"></span> 自定义测试</a></li>
			<li><a href="/download.php?type=problem&id=2435" role="button"><span class="glyphicon glyphicon-download"></span> 下发文件下载</a></li>
			</ul>
<div class="tab-content">
	<div class="tab-pane active" id="tab-statement">
				<article class="top-buffer-md"><h4>题目描述</h4>
<p>花花和啾啾是好朋友，啾啾给花花的奖品是很多好的区间。</p>
<p>对于花花来说，序列 $a_1,a_2,\cdots , a_n$ 一个区间 $[l,r]$ 是好的，需要满足 这个区间内部的第 $i$ 个数字要大于等于 $i$。</p>
<p>比如$a = [3,1,4,1,4]$ 中区间 $[2,3]$ 是好的因为，$a_2 \ge 1, a_3, \ge 2$，区间 $[1, 3]$ 不是好的，因为 $a_2 &lt; 2$。</p>
<p>现在有 $q$ 次操作，每个操作是以下两种：</p>
<ol><li><code>1 p x</code> 表示令 $a_p=x$，即单点修改</li>
<li><code>2 l r</code> 求有多少个子区间 $[l',r'] \in [l,r]$，且满足 $[l',r']$ 是好的</li>
</ol><h4>输入格式</h4>
<p>第一行两个整数 $n, q$。</p>
<p>第二行 $n$ 个整数 $a_i$，表示初始的序列。</p>
<p>接下来 $q$ 行每行 $3$ 个数字表示一种操作。</p>
<h4>输出格式</h4>
<p>输出若干行表示每个询问的答案。</p>
<h4>样例输入1</h4>
<pre><code>6 10
1 5 4 2 6 4
2 2 4
1 3 6
1 4 2
1 1 4
2 2 6
1 2 3
2 2 5
2 1 6
2 1 4
1 5 6</code></pre>
<h4>样例输出1</h4>
<pre><code>5
12
8
15
8</code></pre>
<h4>样例2,3</h4>
<p>见下发文件</p>
<h4>数据范围</h4>
<p>对于$100\%$的数据，$1\le n,q \le 10^6, 1\le a_i, p, x,l, r \le n, l \le r$。</p>
<div class="table-responsive">
<table class="table table-bordered table-text-center table-vertical-middle"><thead><tr><th align="center">子任务编号</th>
<th align="center">$n,q\le$</th>
<th align="center">特殊性质</th>
<th align="center">分数</th>
</tr></thead><tbody><tr><td align="center">1</td>
<td align="center">500</td>
<td align="center"></td>
<td align="center">11</td>
</tr><tr><td align="center">2</td>
<td align="center">5000</td>
<td align="center"></td>
<td align="center">13</td>
</tr><tr><td align="center">3</td>
<td align="center">$2\times 10^5$</td>
<td align="center">A</td>
<td align="center">11</td>
</tr><tr><td align="center">4</td>
<td align="center">$2\times 10^5$</td>
<td align="center">B</td>
<td align="center">14</td>
</tr><tr><td align="center">5</td>
<td align="center">$2\times 10^5$</td>
<td align="center">C</td>
<td align="center">18</td>
</tr><tr><td align="center">6</td>
<td align="center">$2\times 10^5$</td>
<td align="center"></td>
<td align="center">12</td>
</tr><tr><td align="center">7</td>
<td align="center">$10^6$</td>
<td align="center"></td>
<td align="center">21</td>
</tr></tbody></table></div>
<p>A:保证任意时刻的数组 $a$ 与初始数组 $a$ 最多有一个位置不同。</p>
<p>B:保证所有查询操作都有 $l=1,r=n$。</p>
<p>C:保证不存在修改操作。</p>
</article>
	</div>
	<div class="tab-pane" id="tab-submit-answer">
		<div class="top-buffer-sm"></div>
				<form action="/problem/2435" method="post" class="form-horizontal" id="form-answer" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-answer_answer"></div>
<script type="text/javascript">
$('#form-group-answer_answer').source_code_form_group('answer_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="text-center"><button type="submit" id="button-submit-answer" name="submit-answer" value="answer" class="btn btn-default">提交</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-answer').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-answer'] = "";
			$.ajax({
				url : '/problem/2435',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		return ok;
	});
});
</script>	</div>
		<div class="tab-pane" id="tab-custom-test">
		<div class="top-buffer-sm"></div>
		<form action="/problem/2435" method="post" class="form-horizontal" id="form-custom_test" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-custom_test_answer"></div>
<script type="text/javascript">
$('#form-group-custom_test_answer').source_code_form_group('custom_test_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="form-group" id="form-group-custom_test_input"></div>
<script type="text/javascript">
$('#form-group-custom_test_input').text_file_form_group('custom_test_input', '文本文件:input.txt');
</script><div id="div-custom_test_result"></div><div class="text-center"><button type="submit" id="button-submit-custom_test" name="submit-custom_test" value="custom_test" class="btn btn-default">运行</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-custom_test').keydown(function(e) {
		if (e.keyCode == 13 && e.ctrlKey) {
			$('#button-submit-custom_test').click();
		}
	});
	$('#form-custom_test').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-custom_test'] = "";
			$.ajax({
				url : '/problem/2435',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		e.preventDefault();
		if (ok) {
			$(this).ajaxSubmit({
				beforeSubmit: function(formData) {
					formData.push({name: 'submit-custom_test', value: 'custom_test', type: 'submit'});
				},
				success : function(response_text) {custom_test_onsubmit(response_text, $('#div-custom_test_result')[0], '/problem/2435?get=custom-test-status-details')}
			});
		}
	});
});
</script>	</div>
	</div>
			</div>
						<div class="uoj-footer">
				<p>
					<a href="http://zhengruioi.com/problem/2435?locale=zh-cn"><img src="/pictures/lang/cn.png" alt="中文" /></a> 
					<a href="http://zhengruioi.com/problem/2435?locale=en"><img src="/pictures/lang/gb.png" alt="English" /></a>
				</p>
				
				<ul class="list-inline">
					<li>Zhengrui Online Judge</li>
									</ul>
				
				<p>Server time: 2022-11-17 11:38:24 &nbsp; | &nbsp;  <a href="http://www.beian.miit.gov.cn/">浙ICP备17047493号</a></p>
			</div>
					</div>
		<!-- /container -->
	</body>
</html>
<!DOCTYPE html>
<html lang="zh-cn">
	<head>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />
				<title>22冲刺day20-郁金香 - 题目 - Zhengrui Online Judge</title>
		
		<script type="text/javascript">uojHome = 'http://zhengruioi.com'</script>

		<!-- Bootstrap core CSS -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap.min.css?v=2015.5.31" />		<!-- Bootstrap theme -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap-theme.min.css?v=2015.5.31" />
		<!-- Custom styles for this template -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/uoj-theme.css?v=2.33" />		
		<!-- jQuery (necessary for Bootstrap\'s JavaScript plugins) -->
		<script src="http://zhengruioi.com/js/jquery.min.js"></script>		
		<!-- jQuery autosize -->
		<script src="http://zhengruioi.com/js/jquery.autosize.min.js"></script>		<script type="text/javascript">
			$(document).ready(function() {
				$('textarea').autosize();
			});
		</script>
		
		<!-- jQuery cookie -->
		<script src="http://zhengruioi.com/js/jquery.cookie.min.js"></script>		
		<!-- jQuery modal -->
		<script src="http://zhengruioi.com/js/jquery.modal.js"></script>		
		<!-- jQuery tag canvas -->
				
		<!-- Include all compiled plugins (below), or include individual files as needed -->
		<script src="http://zhengruioi.com/js/bootstrap.min.js?v=2015.5.31"></script>		
		<!-- Color converter -->
		<script src="http://zhengruioi.com/js/color-converter.min.js"></script>		
		<!-- uoj -->
		<script src="http://zhengruioi.com/js/uoj.js?v=2016.8.15"></script>		
		<!-- LAB -->
		<script src="http://zhengruioi.com/js/LAB.min.js"></script>
		<!-- UOJ ico -->
		<link rel="shortcut icon" href="http://zhengruioi.com/pictures/UOJ.ico" />
		
				
				
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sweetalert.min.css" />		<script src="http://zhengruioi.com/js/sweetalert.min.js"></script>
				
				
				
				<!-- MathJax -->

        <script type="text/x-mathjax-config">
			MathJax.Hub.Config({
				showProcessingMessages: false,
				tex2jax: {
					inlineMath: [["$", "$"], ["\\\\(", "\\\\)"]],
					processEscapes:true
				},
				menuSettings: {
					zoom: "Hover"
    			}
			});
		</script>
<!--		<script src="//cdn.bootcss.com/mathjax/2.6.0/MathJax.js?config=TeX-AMS_HTML"></script>-->
        <script src="/js/MathJax-2.7.9/MathJax.js?config=TeX-AMS_HTML"></script>
        <!-- <script src="https://cdn.bootcdn.net/ajax/libs/mathjax/2.6.0/config/TeX-AMS_HTML-full.js"></script> -->
				
				<!-- jquery form -->
		<script src="http://zhengruioi.com/js/jquery.form.min.js"></script>				
		
				
				
				
				
				<!-- shjs -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sh_typical.min.css" />		<script src="http://zhengruioi.com/js/sh_main.min.js"></script>		<script type="text/javascript">$(document).ready(function(){sh_highlightDocument()})</script>
				
		
		<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
		<!--[if lt IE 9]>
			<script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
			<script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
		<![endif]-->
		
		<script type="text/javascript">
		before_window_unload_message = null;
		$(window).on('beforeunload', function() {
			if (before_window_unload_message !== null) {
			    return before_window_unload_message;
			}
		});
		</script>
		
			</head>
	<body role="document">
		<div class="container theme-showcase" role="main">
						<div>
				<ul class="nav nav-pills pull-right" role="tablist">
									<li class="dropdown">
						<a href="#" data-toggle="dropdown">
							<span class="uoj-username" data-rating="1503" data-link="0">Meko</span> 						</a>
						<ul class="dropdown-menu" role="menu">
							<li role="presentation"><a href="http://zhengruioi.com/user/msg">私信&nbsp;&nbsp;</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/profile/Meko">个人信息</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/system-msg">系统消息&nbsp;&nbsp;</a></li>
													</ul>
					</li>
					<li role="presentation"><a href="http://zhengruioi.com/logout?_token=qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy">登出</a></li>
								</ul>
				<h1 class="hidden-xs"><a href="http://zhengruioi.com"><img src="http://zhengruioi.com/pictures/UOJ_small.png" alt="UOJ Logo" class="img-rounded" style="width:39px; height:39px;" /></a> Zhengrui Online Judge</h1>
				<h1 class="visible-xs">ZROI</h1>
			</div>
			
			<div class="navbar navbar-default" role="navigation">
	<div class="container-fluid">
		<div class="navbar-header">
			<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".navbar-collapse">
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
			</button>
			<a class="navbar-brand" href="http://zhengruioi.com">ZROI</a>
		</div>
		<div class="navbar-collapse collapse">
			<ul class="nav navbar-nav">
				<li><a href="/contests">比赛</a></li>
				<li><a href="/problems">题库</a></li>
				<li><a href="/submissions">提交记录</a></li>
				<li><a href="/hacks">Hack!</a></li>
				<li><a href="/blogs">博客</a></li>
				<li><a href="/faq">帮助</a></li>
				<li><a href="/rollkings">卷王榜</a></li>
<!--                <li><a href="/rollkings">--><?//= UOJLocale::get('roll kings nav') ?><!--</a></li>-->
									<li><a data-target="#switchModal" href="#" data-toggle="modal">切换</a></li>
					<div class="modal fade in" id="switchModal" tabindex="-1" aria-labelledby="switchModalLabel" aria-hidden="true" style="display: none;">
						<div class="modal-dialog" style="width: 400px;">
							<div class="modal-content">
								<div class="modal-header" style="height: 51px;">
									<h4 class="modal-title" id="switchModalLabel" style="float:left">权限选择</h4>
									<button type="button" class="close" data-dismiss="modal" aria-label="Close" style="float:right">
									<span aria-hidden="true">×</span>
									</button>
								</div>
								<form name="switchChooseForm" method="post">
									<input type="hidden" name="switchChooseFormHiddenInput" id="switchChooseFormHiddenInput" value="switch">
									<div class="modal-body">
										<div class="table-responsive">
											<table class="table table-bordered table-hover table-striped table-text-center">
												<thead><tr>
													<th><label style="margin-bottom: 2px;">
														<input type="checkbox" style="vertical-align: middle;margin-top: 0px;" id="switchChooseAll"><span style="vertical-align: middle"> 全选</span>
													</label></th>
													<th style="vertical-align: middle">团队名称</th>
												</tr></thead>
												<tbody>
													<tr><td><input id="switchCheckbox86" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="86"></td><td>金华一中2022联赛训练</td></tr><tr><td><input id="switchCheckbox98" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="98"></td><td>22暑期CD集训</td></tr><tr><td><input id="switchCheckbox103" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="103"></td><td>22noip赛前20天</td></tr>													
												</tbody>
											</table>
										</div>
									</div>
									<div class="modal-footer">
										<button type="button" class="btn btn-secondary" data-dismiss="modal">取消</button>
										<button type="submit" class="btn btn-primary">确认</button>
									</div>
								</form>
								<script type="text/javascript">
									$("#switchChooseAll").click(function() {
										if (this.checked) {
											$("#switchCheckbox86").prop("checked", true);$("#switchCheckbox98").prop("checked", true);$("#switchCheckbox103").prop("checked", true);										} else {
											$("#switchCheckbox86").prop("checked", false);$("#switchCheckbox98").prop("checked", false);$("#switchCheckbox103").prop("checked", false);										}
									})
								</script>
							</div>
						</div>
					</div>
							</ul>
		</div><!--/.nav-collapse -->
	</div>
</div>
<script type="text/javascript">
function swalConfirm(text) {
	return swal({
		html : text,
		type : 'warning',
		showCancelButton : true,
		allowOutsideClick : false,
		confirmButtonText : 'Yes',
		cancelButtonText : 'No',
		focusCancel : true
	});
}

function switchTo(id) {
	swalConfirm('您确定要切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 吗？')
	.then(function() {
		$.post('/', {
			id : id,
			type : 'switch'
		}, function(msg) {
			if (msg == 'ok') {
				swal('', '成功切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 啦', 'success')
				.then(function() {
					window.location.reload();
				});
			} else swal('', '切换失败，如有疑问请联系蔡老师', 'error');
		});
	});
}
</script>
						
			<div class="uoj-content">
<script src="/js/sec.min.js"></script><script>__canvasWM({content: 'qbYCXKLlZmD5j5oAWdfpCzAeG7f+FK89R8q+o2NnAEU='});</script>
<h1 class="page-header text-center" style="margin-bottom:0px;border-bottom:0px">#2436. 22冲刺day20-郁金香</h1>
<div class="row" style="margin-bottom:20px;border-bottom:1px">
	<div class="col-sm-2"></div>
	<div class="col-sm-8 text-center">
					<div class="btn-group" role="group" aria-label="First group">
				<button type="button" class="uoj-tag btn" disabled="">时间限制：2000 ms</button>
				<button type="button" class="uoj-tag btn" disabled="">空间限制：1024 MiB</button>
				<button type="button" class="uoj-tag btn" disabled="">题目类型：传统型</button>
				<button type="button" class="uoj-tag btn" disabled="">答案检查器：文本比较</button>
			</div>
			</div>
	<div class="col-sm-2 text-right">
		<div class="uoj-click-zan-block" data-id="2436" data-type="P" data-val="0" data-cnt="-13"></div>	</div>
</div>
<a role="button" class="btn btn-info pull-right" href="/problem/2436/statistics"><span class="glyphicon glyphicon-stats"></span> 统计</a>
	<a role="button" class="btn btn-info pull-right" href="/download.php?type=tutorial&id=2436" style="margin-right: 5px"><span class="glyphicon glyphicon-file"></span> 题解</a>

<ul class="nav nav-tabs" role="tablist">
	<li class="active"><a href="#tab-statement" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-book"></span> 描述</a></li>
	<li><a href="#tab-submit-answer" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-upload"></span> 提交</a></li>
		<li><a href="#tab-custom-test" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-console"></span> 自定义测试</a></li>
			<li><a href="/download.php?type=problem&id=2436" role="button"><span class="glyphicon glyphicon-download"></span> 下发文件下载</a></li>
			</ul>
<div class="tab-content">
	<div class="tab-pane active" id="tab-statement">
				<article class="top-buffer-md"><h4>题目描述</h4>
<p>花花和啾啾是好朋友，花花看到了奖品后啾啾带着奖品溜走了，花花想要找到去啾啾位置的最短路。</p>
<p>他们在一个 $k\times k$ 的网格图，$(x,y)$ 与 $(x+1,y)$ 或 $(x,y+1)$ 之间存在一条长度为 $1$ 的双向边。</p>
<p>此外还有额外的 $n$ 条边，从 $(x1_i,y1_i)$ 与 $(x2_i, y2_i)$ 之间存在一条长度为 $|x1_i - x2_i| + |y1_i-y2_i|-1$ 的双向边，保证 $x1_i&lt; x2_i, y1_i \not =y2_i$</p>
<p>现在花花想知道 对于每个无序点对 $(x,y),(x',y')$（即交换起点终点后算一种方案） 之间的最短路之和对<code>998244353</code>取模是多少。</p>
<h4>输入格式</h4>
<p>第一行输入两个整数 $n,k$。
接下来 $n$ 行，每行输入 $4$ 个整数 $x1_i,y1_i,x2_i,y2_i$。</p>
<h4>输出格式</h4>
<p>输出一个数，即最短路之和 $\bmod 998244353$。</p>
<h4>样例输入1</h4>
<pre><code>2 5
2 3 5 2
1 3 4 1</code></pre>
<h4>样例输出1</h4>
<pre><code>985</code></pre>
<h4>样例2,3</h4>
<p>见下发文件</p>
<h4>数据范围</h4>
<p>对于$100\%$的数据，$0\le n\le 500, 1\le k \le 10^9, $</p>
<div class="table-responsive">
<table class="table table-bordered table-text-center table-vertical-middle"><thead><tr><th align="center">子任务编号</th>
<th align="center">$n\le$</th>
<th align="center">$k\le$</th>
<th align="center">分数</th>
</tr></thead><tbody><tr><td align="center">1</td>
<td align="center">100</td>
<td align="center">100</td>
<td align="center">9</td>
</tr><tr><td align="center">2</td>
<td align="center">0</td>
<td align="center">$10^9$</td>
<td align="center">6</td>
</tr><tr><td align="center">3</td>
<td align="center">1</td>
<td align="center">$10^9$</td>
<td align="center">3</td>
</tr><tr><td align="center">4</td>
<td align="center">2</td>
<td align="center">$10^9$</td>
<td align="center">7</td>
</tr><tr><td align="center">5</td>
<td align="center">100</td>
<td align="center">$10^9$</td>
<td align="center">17</td>
</tr><tr><td align="center">6</td>
<td align="center">300</td>
<td align="center">$10^9$</td>
<td align="center">13</td>
</tr><tr><td align="center">7</td>
<td align="center">400</td>
<td align="center">$10^9$</td>
<td align="center">14</td>
</tr><tr><td align="center">8</td>
<td align="center">500</td>
<td align="center">$10^9$</td>
<td align="center">31</td>
</tr></tbody></table></div>
</article>
	</div>
	<div class="tab-pane" id="tab-submit-answer">
		<div class="top-buffer-sm"></div>
				<form action="/problem/2436" method="post" class="form-horizontal" id="form-answer" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-answer_answer"></div>
<script type="text/javascript">
$('#form-group-answer_answer').source_code_form_group('answer_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="text-center"><button type="submit" id="button-submit-answer" name="submit-answer" value="answer" class="btn btn-default">提交</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-answer').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-answer'] = "";
			$.ajax({
				url : '/problem/2436',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		return ok;
	});
});
</script>	</div>
		<div class="tab-pane" id="tab-custom-test">
		<div class="top-buffer-sm"></div>
		<form action="/problem/2436" method="post" class="form-horizontal" id="form-custom_test" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-custom_test_answer"></div>
<script type="text/javascript">
$('#form-group-custom_test_answer').source_code_form_group('custom_test_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="form-group" id="form-group-custom_test_input"></div>
<script type="text/javascript">
$('#form-group-custom_test_input').text_file_form_group('custom_test_input', '文本文件:input.txt');
</script><div id="div-custom_test_result"></div><div class="text-center"><button type="submit" id="button-submit-custom_test" name="submit-custom_test" value="custom_test" class="btn btn-default">运行</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-custom_test').keydown(function(e) {
		if (e.keyCode == 13 && e.ctrlKey) {
			$('#button-submit-custom_test').click();
		}
	});
	$('#form-custom_test').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-custom_test'] = "";
			$.ajax({
				url : '/problem/2436',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		e.preventDefault();
		if (ok) {
			$(this).ajaxSubmit({
				beforeSubmit: function(formData) {
					formData.push({name: 'submit-custom_test', value: 'custom_test', type: 'submit'});
				},
				success : function(response_text) {custom_test_onsubmit(response_text, $('#div-custom_test_result')[0], '/problem/2436?get=custom-test-status-details')}
			});
		}
	});
});
</script>	</div>
	</div>
			</div>
						<div class="uoj-footer">
				<p>
					<a href="http://zhengruioi.com/problem/2436?locale=zh-cn"><img src="/pictures/lang/cn.png" alt="中文" /></a> 
					<a href="http://zhengruioi.com/problem/2436?locale=en"><img src="/pictures/lang/gb.png" alt="English" /></a>
				</p>
				
				<ul class="list-inline">
					<li>Zhengrui Online Judge</li>
									</ul>
				
				<p>Server time: 2022-11-17 11:38:25 &nbsp; | &nbsp;  <a href="http://www.beian.miit.gov.cn/">浙ICP备17047493号</a></p>
			</div>
					</div>
		<!-- /container -->
	</body>
</html>
<!DOCTYPE html>
<html lang="zh-cn">
	<head>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />
				<title>【19金华普及线下】串 - 题目 - Zhengrui Online Judge</title>
		
		<script type="text/javascript">uojHome = 'http://zhengruioi.com'</script>

		<!-- Bootstrap core CSS -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap.min.css?v=2015.5.31" />		<!-- Bootstrap theme -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap-theme.min.css?v=2015.5.31" />
		<!-- Custom styles for this template -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/uoj-theme.css?v=2.33" />		
		<!-- jQuery (necessary for Bootstrap\'s JavaScript plugins) -->
		<script src="http://zhengruioi.com/js/jquery.min.js"></script>		
		<!-- jQuery autosize -->
		<script src="http://zhengruioi.com/js/jquery.autosize.min.js"></script>		<script type="text/javascript">
			$(document).ready(function() {
				$('textarea').autosize();
			});
		</script>
		
		<!-- jQuery cookie -->
		<script src="http://zhengruioi.com/js/jquery.cookie.min.js"></script>		
		<!-- jQuery modal -->
		<script src="http://zhengruioi.com/js/jquery.modal.js"></script>		
		<!-- jQuery tag canvas -->
				
		<!-- Include all compiled plugins (below), or include individual files as needed -->
		<script src="http://zhengruioi.com/js/bootstrap.min.js?v=2015.5.31"></script>		
		<!-- Color converter -->
		<script src="http://zhengruioi.com/js/color-converter.min.js"></script>		
		<!-- uoj -->
		<script src="http://zhengruioi.com/js/uoj.js?v=2016.8.15"></script>		
		<!-- LAB -->
		<script src="http://zhengruioi.com/js/LAB.min.js"></script>
		<!-- UOJ ico -->
		<link rel="shortcut icon" href="http://zhengruioi.com/pictures/UOJ.ico" />
		
				
				
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sweetalert.min.css" />		<script src="http://zhengruioi.com/js/sweetalert.min.js"></script>
				
				
				
				<!-- MathJax -->

        <script type="text/x-mathjax-config">
			MathJax.Hub.Config({
				showProcessingMessages: false,
				tex2jax: {
					inlineMath: [["$", "$"], ["\\\\(", "\\\\)"]],
					processEscapes:true
				},
				menuSettings: {
					zoom: "Hover"
    			}
			});
		</script>
<!--		<script src="//cdn.bootcss.com/mathjax/2.6.0/MathJax.js?config=TeX-AMS_HTML"></script>-->
        <script src="/js/MathJax-2.7.9/MathJax.js?config=TeX-AMS_HTML"></script>
        <!-- <script src="https://cdn.bootcdn.net/ajax/libs/mathjax/2.6.0/config/TeX-AMS_HTML-full.js"></script> -->
				
				<!-- jquery form -->
		<script src="http://zhengruioi.com/js/jquery.form.min.js"></script>				
		
				
				
				
				
				<!-- shjs -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sh_typical.min.css" />		<script src="http://zhengruioi.com/js/sh_main.min.js"></script>		<script type="text/javascript">$(document).ready(function(){sh_highlightDocument()})</script>
				
		
		<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
		<!--[if lt IE 9]>
			<script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
			<script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
		<![endif]-->
		
		<script type="text/javascript">
		before_window_unload_message = null;
		$(window).on('beforeunload', function() {
			if (before_window_unload_message !== null) {
			    return before_window_unload_message;
			}
		});
		</script>
		
			</head>
	<body role="document">
		<div class="container theme-showcase" role="main">
						<div>
				<ul class="nav nav-pills pull-right" role="tablist">
									<li class="dropdown">
						<a href="#" data-toggle="dropdown">
							<span class="uoj-username" data-rating="1503" data-link="0">Meko</span> 						</a>
						<ul class="dropdown-menu" role="menu">
							<li role="presentation"><a href="http://zhengruioi.com/user/msg">私信&nbsp;&nbsp;</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/profile/Meko">个人信息</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/system-msg">系统消息&nbsp;&nbsp;</a></li>
													</ul>
					</li>
					<li role="presentation"><a href="http://zhengruioi.com/logout?_token=qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy">登出</a></li>
								</ul>
				<h1 class="hidden-xs"><a href="http://zhengruioi.com"><img src="http://zhengruioi.com/pictures/UOJ_small.png" alt="UOJ Logo" class="img-rounded" style="width:39px; height:39px;" /></a> Zhengrui Online Judge</h1>
				<h1 class="visible-xs">ZROI</h1>
			</div>
			
			<div class="navbar navbar-default" role="navigation">
	<div class="container-fluid">
		<div class="navbar-header">
			<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".navbar-collapse">
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
			</button>
			<a class="navbar-brand" href="http://zhengruioi.com">ZROI</a>
		</div>
		<div class="navbar-collapse collapse">
			<ul class="nav navbar-nav">
				<li><a href="/contests">比赛</a></li>
				<li><a href="/problems">题库</a></li>
				<li><a href="/submissions">提交记录</a></li>
				<li><a href="/hacks">Hack!</a></li>
				<li><a href="/blogs">博客</a></li>
				<li><a href="/faq">帮助</a></li>
				<li><a href="/rollkings">卷王榜</a></li>
<!--                <li><a href="/rollkings">--><?//= UOJLocale::get('roll kings nav') ?><!--</a></li>-->
									<li><a data-target="#switchModal" href="#" data-toggle="modal">切换</a></li>
					<div class="modal fade in" id="switchModal" tabindex="-1" aria-labelledby="switchModalLabel" aria-hidden="true" style="display: none;">
						<div class="modal-dialog" style="width: 400px;">
							<div class="modal-content">
								<div class="modal-header" style="height: 51px;">
									<h4 class="modal-title" id="switchModalLabel" style="float:left">权限选择</h4>
									<button type="button" class="close" data-dismiss="modal" aria-label="Close" style="float:right">
									<span aria-hidden="true">×</span>
									</button>
								</div>
								<form name="switchChooseForm" method="post">
									<input type="hidden" name="switchChooseFormHiddenInput" id="switchChooseFormHiddenInput" value="switch">
									<div class="modal-body">
										<div class="table-responsive">
											<table class="table table-bordered table-hover table-striped table-text-center">
												<thead><tr>
													<th><label style="margin-bottom: 2px;">
														<input type="checkbox" style="vertical-align: middle;margin-top: 0px;" id="switchChooseAll"><span style="vertical-align: middle"> 全选</span>
													</label></th>
													<th style="vertical-align: middle">团队名称</th>
												</tr></thead>
												<tbody>
													<tr><td><input id="switchCheckbox86" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="86"></td><td>金华一中2022联赛训练</td></tr><tr><td><input id="switchCheckbox98" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="98"></td><td>22暑期CD集训</td></tr><tr><td><input id="switchCheckbox103" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="103"></td><td>22noip赛前20天</td></tr>													
												</tbody>
											</table>
										</div>
									</div>
									<div class="modal-footer">
										<button type="button" class="btn btn-secondary" data-dismiss="modal">取消</button>
										<button type="submit" class="btn btn-primary">确认</button>
									</div>
								</form>
								<script type="text/javascript">
									$("#switchChooseAll").click(function() {
										if (this.checked) {
											$("#switchCheckbox86").prop("checked", true);$("#switchCheckbox98").prop("checked", true);$("#switchCheckbox103").prop("checked", true);										} else {
											$("#switchCheckbox86").prop("checked", false);$("#switchCheckbox98").prop("checked", false);$("#switchCheckbox103").prop("checked", false);										}
									})
								</script>
							</div>
						</div>
					</div>
							</ul>
		</div><!--/.nav-collapse -->
	</div>
</div>
<script type="text/javascript">
function swalConfirm(text) {
	return swal({
		html : text,
		type : 'warning',
		showCancelButton : true,
		allowOutsideClick : false,
		confirmButtonText : 'Yes',
		cancelButtonText : 'No',
		focusCancel : true
	});
}

function switchTo(id) {
	swalConfirm('您确定要切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 吗？')
	.then(function() {
		$.post('/', {
			id : id,
			type : 'switch'
		}, function(msg) {
			if (msg == 'ok') {
				swal('', '成功切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 啦', 'success')
				.then(function() {
					window.location.reload();
				});
			} else swal('', '切换失败，如有疑问请联系蔡老师', 'error');
		});
	});
}
</script>
						
			<div class="uoj-content">
<script src="/js/sec.min.js"></script><script>__canvasWM({content: 'qbYCXKLlZmD5j5oAWdfpC5SkWc0WTiONsMTu3vGUyNA='});</script>
<h1 class="page-header text-center" style="margin-bottom:0px;border-bottom:0px">#589. 【19金华普及线下】串</h1>
<div class="row" style="margin-bottom:20px;border-bottom:1px">
	<div class="col-sm-2"></div>
	<div class="col-sm-8 text-center">
					<div class="btn-group" role="group" aria-label="First group">
				<button type="button" class="uoj-tag btn" disabled="">时间限制：2000 ms</button>
				<button type="button" class="uoj-tag btn" disabled="">空间限制：512 MiB</button>
				<button type="button" class="uoj-tag btn" disabled="">题目类型：传统型</button>
				<button type="button" class="uoj-tag btn" disabled="">答案检查器：文本比较</button>
			</div>
			</div>
	<div class="col-sm-2 text-right">
		<div class="uoj-click-zan-block" data-id="589" data-type="P" data-val="0" data-cnt="-13"></div>	</div>
</div>
<a role="button" class="btn btn-info pull-right" href="/problem/589/statistics"><span class="glyphicon glyphicon-stats"></span> 统计</a>
	<a role="button" class="btn btn-info pull-right" href="/download.php?type=tutorial&id=589" style="margin-right: 5px"><span class="glyphicon glyphicon-file"></span> 题解</a>

<ul class="nav nav-tabs" role="tablist">
	<li class="active"><a href="#tab-statement" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-book"></span> 描述</a></li>
	<li><a href="#tab-submit-answer" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-upload"></span> 提交</a></li>
		<li><a href="#tab-custom-test" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-console"></span> 自定义测试</a></li>
			<li><a href="/download.php?type=problem&id=589" role="button"><span class="glyphicon glyphicon-download"></span> 下发文件下载</a></li>
			</ul>
<div class="tab-content">
	<div class="tab-pane active" id="tab-statement">
				<article class="top-buffer-md"><p>蔡老师想出一个字符串题。</p>
<p>对一个串$t$，他想对这个串做一些变换，得到一些串$t_0, t_1, \dots, t_k$，要求：</p>
<ul><li>$t_0=t, |t_i| = |t|$</li>
<li>$t_i$和$t_{i+1}$至多只有一个位置不同。</li>
</ul><p>那么我们把$r=t_0t_1\dots t_k$这些串拼起来的串成为$t$的变换串。</p>
<p>对于一个串$s$，问有多少个三元组$(i,j,k) (1\leq i&lt; j &lt; k \leq |s|)$满足$s[i\dots k]$是$s[i\dots j]$的变换串。</p>
<h3>输入格式</h3>
<p>第一行一个字符串$s$。</p>
<h3>输出格式</h3>
<p>输出一个整数表示答案。</p>
<h3>样例输入</h3>
<pre><code>abcababc</code></pre>
<h3>样例输出</h3>
<pre><code>5</code></pre>
<h3>数据规模</h3>
<p>对于 $20\%$ 的数据，$1\leq |S| \leq 500$。</p>
<p>对于 $40\%$ 的数据，$1\leq |S| \leq 5000$。</p>
<p>对于另外 $20\%$ 的数据，$|S|$每个字符在$ab$中等概率随机。</p>
<p>对于 $100\%$ 的数据， $|S| \leq 10^5$, $S$为小写字母构成的串。</p>
<h3>题目信息</h3>
<p><strong>题目类型：传统型</strong></p>
<p><strong>输入文件：标准输入</strong></p>
<p><strong>输出文件：标准输出</strong></p>
<p><strong>时间限制：2 s </strong></p>
<p><strong>空间限制：512 MB </strong></p>
<h3>下载</h3>
<p><a href="http://zhengruioi.com/download.php?type=problem&amp;id=589">样例数据下载</a></p>
</article>
	</div>
	<div class="tab-pane" id="tab-submit-answer">
		<div class="top-buffer-sm"></div>
				<form action="/problem/589" method="post" class="form-horizontal" id="form-answer" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-answer_answer"></div>
<script type="text/javascript">
$('#form-group-answer_answer').source_code_form_group('answer_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="text-center"><button type="submit" id="button-submit-answer" name="submit-answer" value="answer" class="btn btn-default">提交</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-answer').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-answer'] = "";
			$.ajax({
				url : '/problem/589',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		return ok;
	});
});
</script>	</div>
		<div class="tab-pane" id="tab-custom-test">
		<div class="top-buffer-sm"></div>
		<form action="/problem/589" method="post" class="form-horizontal" id="form-custom_test" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-custom_test_answer"></div>
<script type="text/javascript">
$('#form-group-custom_test_answer').source_code_form_group('custom_test_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="form-group" id="form-group-custom_test_input"></div>
<script type="text/javascript">
$('#form-group-custom_test_input').text_file_form_group('custom_test_input', '文本文件:input.txt');
</script><div id="div-custom_test_result"></div><div class="text-center"><button type="submit" id="button-submit-custom_test" name="submit-custom_test" value="custom_test" class="btn btn-default">运行</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-custom_test').keydown(function(e) {
		if (e.keyCode == 13 && e.ctrlKey) {
			$('#button-submit-custom_test').click();
		}
	});
	$('#form-custom_test').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-custom_test'] = "";
			$.ajax({
				url : '/problem/589',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		e.preventDefault();
		if (ok) {
			$(this).ajaxSubmit({
				beforeSubmit: function(formData) {
					formData.push({name: 'submit-custom_test', value: 'custom_test', type: 'submit'});
				},
				success : function(response_text) {custom_test_onsubmit(response_text, $('#div-custom_test_result')[0], '/problem/589?get=custom-test-status-details')}
			});
		}
	});
});
</script>	</div>
	</div>
			</div>
						<div class="uoj-footer">
				<p>
					<a href="http://zhengruioi.com/problem/589?locale=zh-cn"><img src="/pictures/lang/cn.png" alt="中文" /></a> 
					<a href="http://zhengruioi.com/problem/589?locale=en"><img src="/pictures/lang/gb.png" alt="English" /></a>
				</p>
				
				<ul class="list-inline">
					<li>Zhengrui Online Judge</li>
									</ul>
				
				<p>Server time: 2022-11-17 11:38:25 &nbsp; | &nbsp;  <a href="http://www.beian.miit.gov.cn/">浙ICP备17047493号</a></p>
			</div>
					</div>
		<!-- /container -->
	</body>
</html>
<!DOCTYPE html>
<html lang="zh-cn">
	<head>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />
				<title>【19金华普及线下】树 - 题目 - Zhengrui Online Judge</title>
		
		<script type="text/javascript">uojHome = 'http://zhengruioi.com'</script>

		<!-- Bootstrap core CSS -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap.min.css?v=2015.5.31" />		<!-- Bootstrap theme -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap-theme.min.css?v=2015.5.31" />
		<!-- Custom styles for this template -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/uoj-theme.css?v=2.33" />		
		<!-- jQuery (necessary for Bootstrap\'s JavaScript plugins) -->
		<script src="http://zhengruioi.com/js/jquery.min.js"></script>		
		<!-- jQuery autosize -->
		<script src="http://zhengruioi.com/js/jquery.autosize.min.js"></script>		<script type="text/javascript">
			$(document).ready(function() {
				$('textarea').autosize();
			});
		</script>
		
		<!-- jQuery cookie -->
		<script src="http://zhengruioi.com/js/jquery.cookie.min.js"></script>		
		<!-- jQuery modal -->
		<script src="http://zhengruioi.com/js/jquery.modal.js"></script>		
		<!-- jQuery tag canvas -->
				
		<!-- Include all compiled plugins (below), or include individual files as needed -->
		<script src="http://zhengruioi.com/js/bootstrap.min.js?v=2015.5.31"></script>		
		<!-- Color converter -->
		<script src="http://zhengruioi.com/js/color-converter.min.js"></script>		
		<!-- uoj -->
		<script src="http://zhengruioi.com/js/uoj.js?v=2016.8.15"></script>		
		<!-- LAB -->
		<script src="http://zhengruioi.com/js/LAB.min.js"></script>
		<!-- UOJ ico -->
		<link rel="shortcut icon" href="http://zhengruioi.com/pictures/UOJ.ico" />
		
				
				
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sweetalert.min.css" />		<script src="http://zhengruioi.com/js/sweetalert.min.js"></script>
				
				
				
				<!-- MathJax -->

        <script type="text/x-mathjax-config">
			MathJax.Hub.Config({
				showProcessingMessages: false,
				tex2jax: {
					inlineMath: [["$", "$"], ["\\\\(", "\\\\)"]],
					processEscapes:true
				},
				menuSettings: {
					zoom: "Hover"
    			}
			});
		</script>
<!--		<script src="//cdn.bootcss.com/mathjax/2.6.0/MathJax.js?config=TeX-AMS_HTML"></script>-->
        <script src="/js/MathJax-2.7.9/MathJax.js?config=TeX-AMS_HTML"></script>
        <!-- <script src="https://cdn.bootcdn.net/ajax/libs/mathjax/2.6.0/config/TeX-AMS_HTML-full.js"></script> -->
				
				<!-- jquery form -->
		<script src="http://zhengruioi.com/js/jquery.form.min.js"></script>				
		
				
				
				
				
				<!-- shjs -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sh_typical.min.css" />		<script src="http://zhengruioi.com/js/sh_main.min.js"></script>		<script type="text/javascript">$(document).ready(function(){sh_highlightDocument()})</script>
				
		
		<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
		<!--[if lt IE 9]>
			<script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
			<script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
		<![endif]-->
		
		<script type="text/javascript">
		before_window_unload_message = null;
		$(window).on('beforeunload', function() {
			if (before_window_unload_message !== null) {
			    return before_window_unload_message;
			}
		});
		</script>
		
			</head>
	<body role="document">
		<div class="container theme-showcase" role="main">
						<div>
				<ul class="nav nav-pills pull-right" role="tablist">
									<li class="dropdown">
						<a href="#" data-toggle="dropdown">
							<span class="uoj-username" data-rating="1503" data-link="0">Meko</span> 						</a>
						<ul class="dropdown-menu" role="menu">
							<li role="presentation"><a href="http://zhengruioi.com/user/msg">私信&nbsp;&nbsp;</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/profile/Meko">个人信息</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/system-msg">系统消息&nbsp;&nbsp;</a></li>
													</ul>
					</li>
					<li role="presentation"><a href="http://zhengruioi.com/logout?_token=qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy">登出</a></li>
								</ul>
				<h1 class="hidden-xs"><a href="http://zhengruioi.com"><img src="http://zhengruioi.com/pictures/UOJ_small.png" alt="UOJ Logo" class="img-rounded" style="width:39px; height:39px;" /></a> Zhengrui Online Judge</h1>
				<h1 class="visible-xs">ZROI</h1>
			</div>
			
			<div class="navbar navbar-default" role="navigation">
	<div class="container-fluid">
		<div class="navbar-header">
			<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".navbar-collapse">
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
			</button>
			<a class="navbar-brand" href="http://zhengruioi.com">ZROI</a>
		</div>
		<div class="navbar-collapse collapse">
			<ul class="nav navbar-nav">
				<li><a href="/contests">比赛</a></li>
				<li><a href="/problems">题库</a></li>
				<li><a href="/submissions">提交记录</a></li>
				<li><a href="/hacks">Hack!</a></li>
				<li><a href="/blogs">博客</a></li>
				<li><a href="/faq">帮助</a></li>
				<li><a href="/rollkings">卷王榜</a></li>
<!--                <li><a href="/rollkings">--><?//= UOJLocale::get('roll kings nav') ?><!--</a></li>-->
									<li><a data-target="#switchModal" href="#" data-toggle="modal">切换</a></li>
					<div class="modal fade in" id="switchModal" tabindex="-1" aria-labelledby="switchModalLabel" aria-hidden="true" style="display: none;">
						<div class="modal-dialog" style="width: 400px;">
							<div class="modal-content">
								<div class="modal-header" style="height: 51px;">
									<h4 class="modal-title" id="switchModalLabel" style="float:left">权限选择</h4>
									<button type="button" class="close" data-dismiss="modal" aria-label="Close" style="float:right">
									<span aria-hidden="true">×</span>
									</button>
								</div>
								<form name="switchChooseForm" method="post">
									<input type="hidden" name="switchChooseFormHiddenInput" id="switchChooseFormHiddenInput" value="switch">
									<div class="modal-body">
										<div class="table-responsive">
											<table class="table table-bordered table-hover table-striped table-text-center">
												<thead><tr>
													<th><label style="margin-bottom: 2px;">
														<input type="checkbox" style="vertical-align: middle;margin-top: 0px;" id="switchChooseAll"><span style="vertical-align: middle"> 全选</span>
													</label></th>
													<th style="vertical-align: middle">团队名称</th>
												</tr></thead>
												<tbody>
													<tr><td><input id="switchCheckbox86" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="86"></td><td>金华一中2022联赛训练</td></tr><tr><td><input id="switchCheckbox98" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="98"></td><td>22暑期CD集训</td></tr><tr><td><input id="switchCheckbox103" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="103"></td><td>22noip赛前20天</td></tr>													
												</tbody>
											</table>
										</div>
									</div>
									<div class="modal-footer">
										<button type="button" class="btn btn-secondary" data-dismiss="modal">取消</button>
										<button type="submit" class="btn btn-primary">确认</button>
									</div>
								</form>
								<script type="text/javascript">
									$("#switchChooseAll").click(function() {
										if (this.checked) {
											$("#switchCheckbox86").prop("checked", true);$("#switchCheckbox98").prop("checked", true);$("#switchCheckbox103").prop("checked", true);										} else {
											$("#switchCheckbox86").prop("checked", false);$("#switchCheckbox98").prop("checked", false);$("#switchCheckbox103").prop("checked", false);										}
									})
								</script>
							</div>
						</div>
					</div>
							</ul>
		</div><!--/.nav-collapse -->
	</div>
</div>
<script type="text/javascript">
function swalConfirm(text) {
	return swal({
		html : text,
		type : 'warning',
		showCancelButton : true,
		allowOutsideClick : false,
		confirmButtonText : 'Yes',
		cancelButtonText : 'No',
		focusCancel : true
	});
}

function switchTo(id) {
	swalConfirm('您确定要切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 吗？')
	.then(function() {
		$.post('/', {
			id : id,
			type : 'switch'
		}, function(msg) {
			if (msg == 'ok') {
				swal('', '成功切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 啦', 'success')
				.then(function() {
					window.location.reload();
				});
			} else swal('', '切换失败，如有疑问请联系蔡老师', 'error');
		});
	});
}
</script>
						
			<div class="uoj-content">
<script src="/js/sec.min.js"></script><script>__canvasWM({content: 'qbYCXKLlZmD5j5oAWdfpC5SkWc0WTiONsMTu3vGUyNA='});</script>
<h1 class="page-header text-center" style="margin-bottom:0px;border-bottom:0px">#590. 【19金华普及线下】树</h1>
<div class="row" style="margin-bottom:20px;border-bottom:1px">
	<div class="col-sm-2"></div>
	<div class="col-sm-8 text-center">
					<div class="btn-group" role="group" aria-label="First group">
				<button type="button" class="uoj-tag btn" disabled="">时间限制：2000 ms</button>
				<button type="button" class="uoj-tag btn" disabled="">空间限制：512 MiB</button>
				<button type="button" class="uoj-tag btn" disabled="">题目类型：传统型</button>
				<button type="button" class="uoj-tag btn" disabled="">答案检查器：文本比较</button>
			</div>
			</div>
	<div class="col-sm-2 text-right">
		<div class="uoj-click-zan-block" data-id="590" data-type="P" data-val="0" data-cnt="-31"></div>	</div>
</div>
<a role="button" class="btn btn-info pull-right" href="/problem/590/statistics"><span class="glyphicon glyphicon-stats"></span> 统计</a>
	<a role="button" class="btn btn-info pull-right" href="/download.php?type=tutorial&id=590" style="margin-right: 5px"><span class="glyphicon glyphicon-file"></span> 题解</a>

<ul class="nav nav-tabs" role="tablist">
	<li class="active"><a href="#tab-statement" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-book"></span> 描述</a></li>
	<li><a href="#tab-submit-answer" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-upload"></span> 提交</a></li>
		<li><a href="#tab-custom-test" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-console"></span> 自定义测试</a></li>
			<li><a href="/download.php?type=problem&id=590" role="button"><span class="glyphicon glyphicon-download"></span> 下发文件下载</a></li>
			</ul>
<div class="tab-content">
	<div class="tab-pane active" id="tab-statement">
				<article class="top-buffer-md"><p>蔡老师家有$n$栋别墅，别墅用$1$到$n$标号。这$n$栋别墅之间由$n-1$条道路相连。有$k$个网友来到了蔡老师家里，蔡老师不知道这$k$个网友在哪里，我们可以认为这些网友每个人都独立等概率的出现在这$n$栋别墅中的一栋。</p>
<p>蔡老师想和网友们碰面，他会找一栋别墅，使得网友们走到他所在的位置的距离总和最小，如果有多种选择，蔡老师会选择编号最小的一个。</p>
<p>蔡老师想知道他的别墅的期望编号是多少，由于答案可能不是整数，请输出这个数字乘上$n^k$后对$998244353$取模的值。</p>
<h3>输入格式</h3>
<p>第一行两个整数$n, k$。</p>
<p>接下来$n-1$行，每行三个整数$u, v, w(1\leq w\leq 10^5)$表示$u$和$v$之间连了一条边权为$w$的边。</p>
<h3>输出格式</h3>
<p>输出一个整数表示答案。</p>
<h3>样例输入</h3>
<pre><code>3 2
1 2 3
1 3 2</code></pre>
<h3>样例输出</h3>
<pre><code>12</code></pre>
<h3>样例解释</h3>
<p>当有至少一个网友在$1$的时候，大家会聚在$1$号点。答案为$1 * 7 + 2 * 1 + 3 * 1 =12$。</p>
<h3>数据规模</h3>
<p>对于 $10\%$ 的数据，$1\leq n, k\leq 5$。</p>
<p>对于另外 $20\%$ 的数据，$1\leq n, k\leq 500$且$k$为奇数。</p>
<p>对于另外 $20\%$ 的数据，$1\leq n, k\leq 500$且$k$为偶数。</p>
<p>对于另外 $20\%$ 的数据，$1\leq n, k\leq 30000$且$k$为奇数。</p>
<p>对于另外 $20\%$ 的数据，$1\leq n, k\leq 30000$，保证这$n$个点形成了一条链。</p>
<p>对于 $100\%$ 的数据， $1\leq n, k \leq 30000$。</p>
<h3>题目信息</h3>
<p><strong>题目类型：传统型</strong></p>
<p><strong>输入文件：标准输入</strong></p>
<p><strong>输出文件：标准输出</strong></p>
<p><strong>时间限制：2 s </strong></p>
<p><strong>空间限制：512 MB </strong></p>
<h3>下载</h3>
<p><a href="http://zhengruioi.com/download.php?type=problem&amp;id=590">样例数据下载</a></p>
</article>
	</div>
	<div class="tab-pane" id="tab-submit-answer">
		<div class="top-buffer-sm"></div>
				<form action="/problem/590" method="post" class="form-horizontal" id="form-answer" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-answer_answer"></div>
<script type="text/javascript">
$('#form-group-answer_answer').source_code_form_group('answer_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="text-center"><button type="submit" id="button-submit-answer" name="submit-answer" value="answer" class="btn btn-default">提交</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-answer').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-answer'] = "";
			$.ajax({
				url : '/problem/590',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		return ok;
	});
});
</script>	</div>
		<div class="tab-pane" id="tab-custom-test">
		<div class="top-buffer-sm"></div>
		<form action="/problem/590" method="post" class="form-horizontal" id="form-custom_test" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-custom_test_answer"></div>
<script type="text/javascript">
$('#form-group-custom_test_answer').source_code_form_group('custom_test_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="form-group" id="form-group-custom_test_input"></div>
<script type="text/javascript">
$('#form-group-custom_test_input').text_file_form_group('custom_test_input', '文本文件:input.txt');
</script><div id="div-custom_test_result"></div><div class="text-center"><button type="submit" id="button-submit-custom_test" name="submit-custom_test" value="custom_test" class="btn btn-default">运行</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-custom_test').keydown(function(e) {
		if (e.keyCode == 13 && e.ctrlKey) {
			$('#button-submit-custom_test').click();
		}
	});
	$('#form-custom_test').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-custom_test'] = "";
			$.ajax({
				url : '/problem/590',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		e.preventDefault();
		if (ok) {
			$(this).ajaxSubmit({
				beforeSubmit: function(formData) {
					formData.push({name: 'submit-custom_test', value: 'custom_test', type: 'submit'});
				},
				success : function(response_text) {custom_test_onsubmit(response_text, $('#div-custom_test_result')[0], '/problem/590?get=custom-test-status-details')}
			});
		}
	});
});
</script>	</div>
	</div>
			</div>
						<div class="uoj-footer">
				<p>
					<a href="http://zhengruioi.com/problem/590?locale=zh-cn"><img src="/pictures/lang/cn.png" alt="中文" /></a> 
					<a href="http://zhengruioi.com/problem/590?locale=en"><img src="/pictures/lang/gb.png" alt="English" /></a>
				</p>
				
				<ul class="list-inline">
					<li>Zhengrui Online Judge</li>
									</ul>
				
				<p>Server time: 2022-11-17 11:38:26 &nbsp; | &nbsp;  <a href="http://www.beian.miit.gov.cn/">浙ICP备17047493号</a></p>
			</div>
					</div>
		<!-- /container -->
	</body>
</html>
<!DOCTYPE html>
<html lang="zh-cn">
	<head>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />
				<title>【19金华普及线下】图 - 题目 - Zhengrui Online Judge</title>
		
		<script type="text/javascript">uojHome = 'http://zhengruioi.com'</script>

		<!-- Bootstrap core CSS -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap.min.css?v=2015.5.31" />		<!-- Bootstrap theme -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap-theme.min.css?v=2015.5.31" />
		<!-- Custom styles for this template -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/uoj-theme.css?v=2.33" />		
		<!-- jQuery (necessary for Bootstrap\'s JavaScript plugins) -->
		<script src="http://zhengruioi.com/js/jquery.min.js"></script>		
		<!-- jQuery autosize -->
		<script src="http://zhengruioi.com/js/jquery.autosize.min.js"></script>		<script type="text/javascript">
			$(document).ready(function() {
				$('textarea').autosize();
			});
		</script>
		
		<!-- jQuery cookie -->
		<script src="http://zhengruioi.com/js/jquery.cookie.min.js"></script>		
		<!-- jQuery modal -->
		<script src="http://zhengruioi.com/js/jquery.modal.js"></script>		
		<!-- jQuery tag canvas -->
				
		<!-- Include all compiled plugins (below), or include individual files as needed -->
		<script src="http://zhengruioi.com/js/bootstrap.min.js?v=2015.5.31"></script>		
		<!-- Color converter -->
		<script src="http://zhengruioi.com/js/color-converter.min.js"></script>		
		<!-- uoj -->
		<script src="http://zhengruioi.com/js/uoj.js?v=2016.8.15"></script>		
		<!-- LAB -->
		<script src="http://zhengruioi.com/js/LAB.min.js"></script>
		<!-- UOJ ico -->
		<link rel="shortcut icon" href="http://zhengruioi.com/pictures/UOJ.ico" />
		
				
				
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sweetalert.min.css" />		<script src="http://zhengruioi.com/js/sweetalert.min.js"></script>
				
				
				
				<!-- MathJax -->

        <script type="text/x-mathjax-config">
			MathJax.Hub.Config({
				showProcessingMessages: false,
				tex2jax: {
					inlineMath: [["$", "$"], ["\\\\(", "\\\\)"]],
					processEscapes:true
				},
				menuSettings: {
					zoom: "Hover"
    			}
			});
		</script>
<!--		<script src="//cdn.bootcss.com/mathjax/2.6.0/MathJax.js?config=TeX-AMS_HTML"></script>-->
        <script src="/js/MathJax-2.7.9/MathJax.js?config=TeX-AMS_HTML"></script>
        <!-- <script src="https://cdn.bootcdn.net/ajax/libs/mathjax/2.6.0/config/TeX-AMS_HTML-full.js"></script> -->
				
				<!-- jquery form -->
		<script src="http://zhengruioi.com/js/jquery.form.min.js"></script>				
		
				
				
				
				
				<!-- shjs -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sh_typical.min.css" />		<script src="http://zhengruioi.com/js/sh_main.min.js"></script>		<script type="text/javascript">$(document).ready(function(){sh_highlightDocument()})</script>
				
		
		<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
		<!--[if lt IE 9]>
			<script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
			<script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
		<![endif]-->
		
		<script type="text/javascript">
		before_window_unload_message = null;
		$(window).on('beforeunload', function() {
			if (before_window_unload_message !== null) {
			    return before_window_unload_message;
			}
		});
		</script>
		
			</head>
	<body role="document">
		<div class="container theme-showcase" role="main">
						<div>
				<ul class="nav nav-pills pull-right" role="tablist">
									<li class="dropdown">
						<a href="#" data-toggle="dropdown">
							<span class="uoj-username" data-rating="1503" data-link="0">Meko</span> 						</a>
						<ul class="dropdown-menu" role="menu">
							<li role="presentation"><a href="http://zhengruioi.com/user/msg">私信&nbsp;&nbsp;</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/profile/Meko">个人信息</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/system-msg">系统消息&nbsp;&nbsp;</a></li>
													</ul>
					</li>
					<li role="presentation"><a href="http://zhengruioi.com/logout?_token=qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy">登出</a></li>
								</ul>
				<h1 class="hidden-xs"><a href="http://zhengruioi.com"><img src="http://zhengruioi.com/pictures/UOJ_small.png" alt="UOJ Logo" class="img-rounded" style="width:39px; height:39px;" /></a> Zhengrui Online Judge</h1>
				<h1 class="visible-xs">ZROI</h1>
			</div>
			
			<div class="navbar navbar-default" role="navigation">
	<div class="container-fluid">
		<div class="navbar-header">
			<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".navbar-collapse">
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
			</button>
			<a class="navbar-brand" href="http://zhengruioi.com">ZROI</a>
		</div>
		<div class="navbar-collapse collapse">
			<ul class="nav navbar-nav">
				<li><a href="/contests">比赛</a></li>
				<li><a href="/problems">题库</a></li>
				<li><a href="/submissions">提交记录</a></li>
				<li><a href="/hacks">Hack!</a></li>
				<li><a href="/blogs">博客</a></li>
				<li><a href="/faq">帮助</a></li>
				<li><a href="/rollkings">卷王榜</a></li>
<!--                <li><a href="/rollkings">--><?//= UOJLocale::get('roll kings nav') ?><!--</a></li>-->
									<li><a data-target="#switchModal" href="#" data-toggle="modal">切换</a></li>
					<div class="modal fade in" id="switchModal" tabindex="-1" aria-labelledby="switchModalLabel" aria-hidden="true" style="display: none;">
						<div class="modal-dialog" style="width: 400px;">
							<div class="modal-content">
								<div class="modal-header" style="height: 51px;">
									<h4 class="modal-title" id="switchModalLabel" style="float:left">权限选择</h4>
									<button type="button" class="close" data-dismiss="modal" aria-label="Close" style="float:right">
									<span aria-hidden="true">×</span>
									</button>
								</div>
								<form name="switchChooseForm" method="post">
									<input type="hidden" name="switchChooseFormHiddenInput" id="switchChooseFormHiddenInput" value="switch">
									<div class="modal-body">
										<div class="table-responsive">
											<table class="table table-bordered table-hover table-striped table-text-center">
												<thead><tr>
													<th><label style="margin-bottom: 2px;">
														<input type="checkbox" style="vertical-align: middle;margin-top: 0px;" id="switchChooseAll"><span style="vertical-align: middle"> 全选</span>
													</label></th>
													<th style="vertical-align: middle">团队名称</th>
												</tr></thead>
												<tbody>
													<tr><td><input id="switchCheckbox86" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="86"></td><td>金华一中2022联赛训练</td></tr><tr><td><input id="switchCheckbox98" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="98"></td><td>22暑期CD集训</td></tr><tr><td><input id="switchCheckbox103" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="103"></td><td>22noip赛前20天</td></tr>													
												</tbody>
											</table>
										</div>
									</div>
									<div class="modal-footer">
										<button type="button" class="btn btn-secondary" data-dismiss="modal">取消</button>
										<button type="submit" class="btn btn-primary">确认</button>
									</div>
								</form>
								<script type="text/javascript">
									$("#switchChooseAll").click(function() {
										if (this.checked) {
											$("#switchCheckbox86").prop("checked", true);$("#switchCheckbox98").prop("checked", true);$("#switchCheckbox103").prop("checked", true);										} else {
											$("#switchCheckbox86").prop("checked", false);$("#switchCheckbox98").prop("checked", false);$("#switchCheckbox103").prop("checked", false);										}
									})
								</script>
							</div>
						</div>
					</div>
							</ul>
		</div><!--/.nav-collapse -->
	</div>
</div>
<script type="text/javascript">
function swalConfirm(text) {
	return swal({
		html : text,
		type : 'warning',
		showCancelButton : true,
		allowOutsideClick : false,
		confirmButtonText : 'Yes',
		cancelButtonText : 'No',
		focusCancel : true
	});
}

function switchTo(id) {
	swalConfirm('您确定要切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 吗？')
	.then(function() {
		$.post('/', {
			id : id,
			type : 'switch'
		}, function(msg) {
			if (msg == 'ok') {
				swal('', '成功切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 啦', 'success')
				.then(function() {
					window.location.reload();
				});
			} else swal('', '切换失败，如有疑问请联系蔡老师', 'error');
		});
	});
}
</script>
						
			<div class="uoj-content">
<script src="/js/sec.min.js"></script><script>__canvasWM({content: 'qbYCXKLlZmD5j5oAWdfpC5SkWc0WTiONsMTu3vGUyNA='});</script>
<h1 class="page-header text-center" style="margin-bottom:0px;border-bottom:0px">#591. 【19金华普及线下】图</h1>
<div class="row" style="margin-bottom:20px;border-bottom:1px">
	<div class="col-sm-2"></div>
	<div class="col-sm-8 text-center">
					<div class="btn-group" role="group" aria-label="First group">
				<button type="button" class="uoj-tag btn" disabled="">时间限制：2000 ms</button>
				<button type="button" class="uoj-tag btn" disabled="">空间限制：512 MiB</button>
				<button type="button" class="uoj-tag btn" disabled="">题目类型：传统型</button>
				<button type="button" class="uoj-tag btn" disabled="">答案检查器：文本比较</button>
			</div>
			</div>
	<div class="col-sm-2 text-right">
		<div class="uoj-click-zan-block" data-id="591" data-type="P" data-val="0" data-cnt="-25"></div>	</div>
</div>
<a role="button" class="btn btn-info pull-right" href="/problem/591/statistics"><span class="glyphicon glyphicon-stats"></span> 统计</a>
	<a role="button" class="btn btn-info pull-right" href="/download.php?type=tutorial&id=591" style="margin-right: 5px"><span class="glyphicon glyphicon-file"></span> 题解</a>

<ul class="nav nav-tabs" role="tablist">
	<li class="active"><a href="#tab-statement" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-book"></span> 描述</a></li>
	<li><a href="#tab-submit-answer" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-upload"></span> 提交</a></li>
		<li><a href="#tab-custom-test" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-console"></span> 自定义测试</a></li>
			<li><a href="/download.php?type=problem&id=591" role="button"><span class="glyphicon glyphicon-download"></span> 下发文件下载</a></li>
			</ul>
<div class="tab-content">
	<div class="tab-pane active" id="tab-statement">
				<article class="top-buffer-md"><p>作为一个优秀的老师，蔡老师觉得押题是一项基本的技能。蔡老师夜观天象觉得今年省选一定会有一道线图的题。</p>
<p>在一张无向图$G$上，我们可以对它进行一些非常有趣的变换，比如说对偶，又或者说取补。这样的操作往往可以赋予一些传统的问题新的活力。例如求补图的连通性、补图的最短路等等，都是非常有趣的问题。 最近蔡老师知道了一种新的变换:求原图的线图 (line graph)。对于无向图$G=?V,E?$，它的线图 $L(G)$也是一个无向图:</p>
<ul><li>它的点集为 $E$，每个点唯一对应着原图的一条边。</li>
<li>两个点之间有边当且仅当这两个点对应的边在原图上有公共点(注意不会有自环)。</li>
</ul><p>如果我们我们把图$G$的点和边都赋上权值。在$L(G)$中，我们可以认为点权为原图中对应边的边权，边权为原图中对应公共点的点权。</p>
<p>蔡老师想要从最简单的入手，即计算$L^k(G)$ 的最小生成树( $L^k(G)$ 表示对 $G$ 求 $k$ 次线图)。</p>
<h3>输入格式</h3>
<p>第一行两个整数$n, m, k$。</p>
<p>接下来一行$n$个整数，表示$1$到$n$这些点的点权$p (1\leq p\leq 10^5)$。</p>
<p>接下来$m$行，每行三个整数$u, v, w(1\leq u,v \leq n, 1\leq w\leq 10^5)$，表示$u$和$v$之间连了一条边权为$w$的边。</p>
<p>保证图中没有自环和重边，并且图是联通的。</p>
<h3>输出格式</h3>
<p>输出一个数，表示最小生成树中边的边权和。</p>
<h3>样例输入</h3>
<pre><code>3 3 1
2 1 3
1 2 3
1 3 2
2 3 1</code></pre>
<h3>样例输出</h3>
<pre><code>3</code></pre>
<h3>数据规模</h3>
<p>对于 $10\%$ 的数据，$k=0$。</p>
<p>对于另外 $10\%$ 的数据，$1\leq n \leq 1000, 1\leq m\leq 2000, k=1$。</p>
<p>对于另外 $20\%$ 的数据，$k=1$。</p>
<p>对于另外 $10\%$ 的数据，$1\leq n \leq 50, k=2$。</p>
<p>对于另外 $10\%$ 的数据，$1\leq n\leq 500, 1\leq m \leq 2000, k=2$。</p>
<p>对于 $100\%$ 的数据， $1\leq n\leq 10^5, 1\leq m \leq 2 * 10^5,0\leq k\leq 2$。</p>
<h3>题目信息</h3>
<p><strong>题目类型：传统型</strong></p>
<p><strong>输入文件：标准输入</strong></p>
<p><strong>输出文件：标准输出</strong></p>
<p><strong>时间限制：2 s </strong></p>
<p><strong>空间限制：512 MB </strong></p>
<h3>下载</h3>
<p><a href="http://zhengruioi.com/download.php?type=problem&amp;id=591">样例数据下载</a></p>
</article>
	</div>
	<div class="tab-pane" id="tab-submit-answer">
		<div class="top-buffer-sm"></div>
				<form action="/problem/591" method="post" class="form-horizontal" id="form-answer" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-answer_answer"></div>
<script type="text/javascript">
$('#form-group-answer_answer').source_code_form_group('answer_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="text-center"><button type="submit" id="button-submit-answer" name="submit-answer" value="answer" class="btn btn-default">提交</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-answer').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-answer'] = "";
			$.ajax({
				url : '/problem/591',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		return ok;
	});
});
</script>	</div>
		<div class="tab-pane" id="tab-custom-test">
		<div class="top-buffer-sm"></div>
		<form action="/problem/591" method="post" class="form-horizontal" id="form-custom_test" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-custom_test_answer"></div>
<script type="text/javascript">
$('#form-group-custom_test_answer').source_code_form_group('custom_test_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="form-group" id="form-group-custom_test_input"></div>
<script type="text/javascript">
$('#form-group-custom_test_input').text_file_form_group('custom_test_input', '文本文件:input.txt');
</script><div id="div-custom_test_result"></div><div class="text-center"><button type="submit" id="button-submit-custom_test" name="submit-custom_test" value="custom_test" class="btn btn-default">运行</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-custom_test').keydown(function(e) {
		if (e.keyCode == 13 && e.ctrlKey) {
			$('#button-submit-custom_test').click();
		}
	});
	$('#form-custom_test').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-custom_test'] = "";
			$.ajax({
				url : '/problem/591',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		e.preventDefault();
		if (ok) {
			$(this).ajaxSubmit({
				beforeSubmit: function(formData) {
					formData.push({name: 'submit-custom_test', value: 'custom_test', type: 'submit'});
				},
				success : function(response_text) {custom_test_onsubmit(response_text, $('#div-custom_test_result')[0], '/problem/591?get=custom-test-status-details')}
			});
		}
	});
});
</script>	</div>
	</div>
			</div>
						<div class="uoj-footer">
				<p>
					<a href="http://zhengruioi.com/problem/591?locale=zh-cn"><img src="/pictures/lang/cn.png" alt="中文" /></a> 
					<a href="http://zhengruioi.com/problem/591?locale=en"><img src="/pictures/lang/gb.png" alt="English" /></a>
				</p>
				
				<ul class="list-inline">
					<li>Zhengrui Online Judge</li>
									</ul>
				
				<p>Server time: 2022-11-17 11:38:26 &nbsp; | &nbsp;  <a href="http://www.beian.miit.gov.cn/">浙ICP备17047493号</a></p>
			</div>
					</div>
		<!-- /container -->
	</body>
</html>
<!DOCTYPE html>
<html lang="zh-cn">
	<head>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />
				<title>18ABday5-友谊巨轮 - 题目 - Zhengrui Online Judge</title>
		
		<script type="text/javascript">uojHome = 'http://zhengruioi.com'</script>

		<!-- Bootstrap core CSS -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap.min.css?v=2015.5.31" />		<!-- Bootstrap theme -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap-theme.min.css?v=2015.5.31" />
		<!-- Custom styles for this template -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/uoj-theme.css?v=2.33" />		
		<!-- jQuery (necessary for Bootstrap\'s JavaScript plugins) -->
		<script src="http://zhengruioi.com/js/jquery.min.js"></script>		
		<!-- jQuery autosize -->
		<script src="http://zhengruioi.com/js/jquery.autosize.min.js"></script>		<script type="text/javascript">
			$(document).ready(function() {
				$('textarea').autosize();
			});
		</script>
		
		<!-- jQuery cookie -->
		<script src="http://zhengruioi.com/js/jquery.cookie.min.js"></script>		
		<!-- jQuery modal -->
		<script src="http://zhengruioi.com/js/jquery.modal.js"></script>		
		<!-- jQuery tag canvas -->
				
		<!-- Include all compiled plugins (below), or include individual files as needed -->
		<script src="http://zhengruioi.com/js/bootstrap.min.js?v=2015.5.31"></script>		
		<!-- Color converter -->
		<script src="http://zhengruioi.com/js/color-converter.min.js"></script>		
		<!-- uoj -->
		<script src="http://zhengruioi.com/js/uoj.js?v=2016.8.15"></script>		
		<!-- LAB -->
		<script src="http://zhengruioi.com/js/LAB.min.js"></script>
		<!-- UOJ ico -->
		<link rel="shortcut icon" href="http://zhengruioi.com/pictures/UOJ.ico" />
		
				
				
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sweetalert.min.css" />		<script src="http://zhengruioi.com/js/sweetalert.min.js"></script>
				
				
				
				<!-- MathJax -->

        <script type="text/x-mathjax-config">
			MathJax.Hub.Config({
				showProcessingMessages: false,
				tex2jax: {
					inlineMath: [["$", "$"], ["\\\\(", "\\\\)"]],
					processEscapes:true
				},
				menuSettings: {
					zoom: "Hover"
    			}
			});
		</script>
<!--		<script src="//cdn.bootcss.com/mathjax/2.6.0/MathJax.js?config=TeX-AMS_HTML"></script>-->
        <script src="/js/MathJax-2.7.9/MathJax.js?config=TeX-AMS_HTML"></script>
        <!-- <script src="https://cdn.bootcdn.net/ajax/libs/mathjax/2.6.0/config/TeX-AMS_HTML-full.js"></script> -->
				
				<!-- jquery form -->
		<script src="http://zhengruioi.com/js/jquery.form.min.js"></script>				
		
				
				
				
				
				<!-- shjs -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sh_typical.min.css" />		<script src="http://zhengruioi.com/js/sh_main.min.js"></script>		<script type="text/javascript">$(document).ready(function(){sh_highlightDocument()})</script>
				
		
		<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
		<!--[if lt IE 9]>
			<script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
			<script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
		<![endif]-->
		
		<script type="text/javascript">
		before_window_unload_message = null;
		$(window).on('beforeunload', function() {
			if (before_window_unload_message !== null) {
			    return before_window_unload_message;
			}
		});
		</script>
		
			</head>
	<body role="document">
		<div class="container theme-showcase" role="main">
						<div>
				<ul class="nav nav-pills pull-right" role="tablist">
									<li class="dropdown">
						<a href="#" data-toggle="dropdown">
							<span class="uoj-username" data-rating="1503" data-link="0">Meko</span> 						</a>
						<ul class="dropdown-menu" role="menu">
							<li role="presentation"><a href="http://zhengruioi.com/user/msg">私信&nbsp;&nbsp;</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/profile/Meko">个人信息</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/system-msg">系统消息&nbsp;&nbsp;</a></li>
													</ul>
					</li>
					<li role="presentation"><a href="http://zhengruioi.com/logout?_token=qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy">登出</a></li>
								</ul>
				<h1 class="hidden-xs"><a href="http://zhengruioi.com"><img src="http://zhengruioi.com/pictures/UOJ_small.png" alt="UOJ Logo" class="img-rounded" style="width:39px; height:39px;" /></a> Zhengrui Online Judge</h1>
				<h1 class="visible-xs">ZROI</h1>
			</div>
			
			<div class="navbar navbar-default" role="navigation">
	<div class="container-fluid">
		<div class="navbar-header">
			<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".navbar-collapse">
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
			</button>
			<a class="navbar-brand" href="http://zhengruioi.com">ZROI</a>
		</div>
		<div class="navbar-collapse collapse">
			<ul class="nav navbar-nav">
				<li><a href="/contests">比赛</a></li>
				<li><a href="/problems">题库</a></li>
				<li><a href="/submissions">提交记录</a></li>
				<li><a href="/hacks">Hack!</a></li>
				<li><a href="/blogs">博客</a></li>
				<li><a href="/faq">帮助</a></li>
				<li><a href="/rollkings">卷王榜</a></li>
<!--                <li><a href="/rollkings">--><?//= UOJLocale::get('roll kings nav') ?><!--</a></li>-->
									<li><a data-target="#switchModal" href="#" data-toggle="modal">切换</a></li>
					<div class="modal fade in" id="switchModal" tabindex="-1" aria-labelledby="switchModalLabel" aria-hidden="true" style="display: none;">
						<div class="modal-dialog" style="width: 400px;">
							<div class="modal-content">
								<div class="modal-header" style="height: 51px;">
									<h4 class="modal-title" id="switchModalLabel" style="float:left">权限选择</h4>
									<button type="button" class="close" data-dismiss="modal" aria-label="Close" style="float:right">
									<span aria-hidden="true">×</span>
									</button>
								</div>
								<form name="switchChooseForm" method="post">
									<input type="hidden" name="switchChooseFormHiddenInput" id="switchChooseFormHiddenInput" value="switch">
									<div class="modal-body">
										<div class="table-responsive">
											<table class="table table-bordered table-hover table-striped table-text-center">
												<thead><tr>
													<th><label style="margin-bottom: 2px;">
														<input type="checkbox" style="vertical-align: middle;margin-top: 0px;" id="switchChooseAll"><span style="vertical-align: middle"> 全选</span>
													</label></th>
													<th style="vertical-align: middle">团队名称</th>
												</tr></thead>
												<tbody>
													<tr><td><input id="switchCheckbox86" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="86"></td><td>金华一中2022联赛训练</td></tr><tr><td><input id="switchCheckbox98" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="98"></td><td>22暑期CD集训</td></tr><tr><td><input id="switchCheckbox103" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="103"></td><td>22noip赛前20天</td></tr>													
												</tbody>
											</table>
										</div>
									</div>
									<div class="modal-footer">
										<button type="button" class="btn btn-secondary" data-dismiss="modal">取消</button>
										<button type="submit" class="btn btn-primary">确认</button>
									</div>
								</form>
								<script type="text/javascript">
									$("#switchChooseAll").click(function() {
										if (this.checked) {
											$("#switchCheckbox86").prop("checked", true);$("#switchCheckbox98").prop("checked", true);$("#switchCheckbox103").prop("checked", true);										} else {
											$("#switchCheckbox86").prop("checked", false);$("#switchCheckbox98").prop("checked", false);$("#switchCheckbox103").prop("checked", false);										}
									})
								</script>
							</div>
						</div>
					</div>
							</ul>
		</div><!--/.nav-collapse -->
	</div>
</div>
<script type="text/javascript">
function swalConfirm(text) {
	return swal({
		html : text,
		type : 'warning',
		showCancelButton : true,
		allowOutsideClick : false,
		confirmButtonText : 'Yes',
		cancelButtonText : 'No',
		focusCancel : true
	});
}

function switchTo(id) {
	swalConfirm('您确定要切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 吗？')
	.then(function() {
		$.post('/', {
			id : id,
			type : 'switch'
		}, function(msg) {
			if (msg == 'ok') {
				swal('', '成功切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 啦', 'success')
				.then(function() {
					window.location.reload();
				});
			} else swal('', '切换失败，如有疑问请联系蔡老师', 'error');
		});
	});
}
</script>
						
			<div class="uoj-content">
<script src="/js/sec.min.js"></script><script>__canvasWM({content: 'qbYCXKLlZmD5j5oAWdfpC8ZoKdMJp7C6kOoLEzIkQ1Q='});</script>
<h1 class="page-header text-center" style="margin-bottom:0px;border-bottom:0px">#258. 18ABday5-友谊巨轮</h1>
<div class="row" style="margin-bottom:20px;border-bottom:1px">
	<div class="col-sm-2"></div>
	<div class="col-sm-8 text-center">
					<div class="btn-group" role="group" aria-label="First group">
				<button type="button" class="uoj-tag btn" disabled="">时间限制：4000 ms</button>
				<button type="button" class="uoj-tag btn" disabled="">空间限制：512 MiB</button>
				<button type="button" class="uoj-tag btn" disabled="">题目类型：传统型</button>
				<button type="button" class="uoj-tag btn" disabled="">答案检查器：文本比较</button>
			</div>
			</div>
	<div class="col-sm-2 text-right">
		<div class="uoj-click-zan-block" data-id="258" data-type="P" data-val="0" data-cnt="-28"></div>	</div>
</div>
<a role="button" class="btn btn-info pull-right" href="/problem/258/statistics"><span class="glyphicon glyphicon-stats"></span> 统计</a>
	<a role="button" class="btn btn-info pull-right" href="/download.php?type=tutorial&id=258" style="margin-right: 5px"><span class="glyphicon glyphicon-file"></span> 题解</a>

<ul class="nav nav-tabs" role="tablist">
	<li class="active"><a href="#tab-statement" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-book"></span> 描述</a></li>
	<li><a href="#tab-submit-answer" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-upload"></span> 提交</a></li>
		<li><a href="#tab-custom-test" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-console"></span> 自定义测试</a></li>
			<li><a href="/download.php?type=problem&id=258" role="button"><span class="glyphicon glyphicon-download"></span> 下发文件下载</a></li>
			</ul>
<div class="tab-content">
	<div class="tab-pane active" id="tab-statement">
				<article class="top-buffer-md"><p>作为一场快乐的模拟赛，需要一道歌颂友谊的题目。</p>
<p>你从来不知道，友谊的巨轮是单向的，直到有一天他和她在了一起。</p>
<p>这个地球上一共有$n$个人，他们之间会互相发消息。在每个时刻，$a$与$b$之间互相发了$c$条消息。对于每个人，他友谊的巨轮为最近$m$个时刻里与他发消息最多的人，如果有多个发消息最多的人，那么巨轮为这里面最近发的人。如果这个人在最近$m$个时刻里面没有与任何人发过消息，那么它没有友谊的巨轮。</p>
<p>在这个题目里面，我们设定一个时刻只有某两个人之间互相发了$c$条消息。</p>
<p>你获得了上帝视角，知道了每个时刻哪两个人发了消息。你经常会发现Alice和Bob发完晚安之后，又和Charlie聊一整晚。Bob的巨轮是Alice，但是Alice的巨轮却是Charlie。你想知道，每个时刻发完消息之后，有多少的人的巨轮是单向的，即他的巨轮的巨轮不是他。</p>
<h3>输入格式</h3>
<p>第一行一个整数$T$，表示数据组数。</p>
<p>每组数据第一行三个整数，表示$n,k,m$，表示总人数，总的时刻数，以及巨轮要求的是最近$m$个时刻。</p>
<p>接下来$k$行，每行三个正整数$a,b,c(1\leq a,b\leq n,1\leq c\leq 10^9, a\neq b)$。</p>
<h3>输出格式</h3>
<p>对于每组数据输出$k$行，表示每个时刻多少个人的巨轮是单向的。</p>
<h3>样例1</h3>
<h4>样例输入</h4>
<pre>
1
5 7 5
1 2 1
1 3 1
2 4 1
1 2 2
4 5 2
3 4 2
1 5 1
</pre>

<h4>样例输出</h4>
<pre>
0
1
0
2
1
1
1
</pre>

<h3>样例2</h3>
<p>见下载文件</p>
<h3>限制与规定</h3>
<p>对于 $20\%$ 的数据，有 $1\leq n, k, m\leq 100$。</p>
<p>对于 $40\%$ 的数据，有 $1\leq n, k, m\leq 10^3$。</p>
<p>对于另外 $20\%$ 的数据，有 $m=k$。</p>
<p>对于另外 $10\%$ 的数据，有 $T=1$。</p>
<p>对于 $100\%$ 的数据，有 $1\leq n, k, m\leq 10^5, T\leq 5$。</p>
<p><strong>时间限制</strong>：$4\texttt{s}$</p>
<p><strong>空间限制</strong>：$512\texttt{MB}$</p>
<h3>下载</h3>
<p><a href="/download.php?type=problem&amp;id=258">样例数据下载</a></p>
</article>
	</div>
	<div class="tab-pane" id="tab-submit-answer">
		<div class="top-buffer-sm"></div>
				<form action="/problem/258" method="post" class="form-horizontal" id="form-answer" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-answer_answer"></div>
<script type="text/javascript">
$('#form-group-answer_answer').source_code_form_group('answer_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="text-center"><button type="submit" id="button-submit-answer" name="submit-answer" value="answer" class="btn btn-default">提交</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-answer').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-answer'] = "";
			$.ajax({
				url : '/problem/258',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		return ok;
	});
});
</script>	</div>
		<div class="tab-pane" id="tab-custom-test">
		<div class="top-buffer-sm"></div>
		<form action="/problem/258" method="post" class="form-horizontal" id="form-custom_test" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-custom_test_answer"></div>
<script type="text/javascript">
$('#form-group-custom_test_answer').source_code_form_group('custom_test_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="form-group" id="form-group-custom_test_input"></div>
<script type="text/javascript">
$('#form-group-custom_test_input').text_file_form_group('custom_test_input', '文本文件:input.txt');
</script><div id="div-custom_test_result"></div><div class="text-center"><button type="submit" id="button-submit-custom_test" name="submit-custom_test" value="custom_test" class="btn btn-default">运行</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-custom_test').keydown(function(e) {
		if (e.keyCode == 13 && e.ctrlKey) {
			$('#button-submit-custom_test').click();
		}
	});
	$('#form-custom_test').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-custom_test'] = "";
			$.ajax({
				url : '/problem/258',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		e.preventDefault();
		if (ok) {
			$(this).ajaxSubmit({
				beforeSubmit: function(formData) {
					formData.push({name: 'submit-custom_test', value: 'custom_test', type: 'submit'});
				},
				success : function(response_text) {custom_test_onsubmit(response_text, $('#div-custom_test_result')[0], '/problem/258?get=custom-test-status-details')}
			});
		}
	});
});
</script>	</div>
	</div>
			</div>
						<div class="uoj-footer">
				<p>
					<a href="http://zhengruioi.com/problem/258?locale=zh-cn"><img src="/pictures/lang/cn.png" alt="中文" /></a> 
					<a href="http://zhengruioi.com/problem/258?locale=en"><img src="/pictures/lang/gb.png" alt="English" /></a>
				</p>
				
				<ul class="list-inline">
					<li>Zhengrui Online Judge</li>
									</ul>
				
				<p>Server time: 2022-11-17 11:38:26 &nbsp; | &nbsp;  <a href="http://www.beian.miit.gov.cn/">浙ICP备17047493号</a></p>
			</div>
					</div>
		<!-- /container -->
	</body>
</html>
<!DOCTYPE html>
<html lang="zh-cn">
	<head>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />
				<title>18ABday5-璀璨光滑 - 题目 - Zhengrui Online Judge</title>
		
		<script type="text/javascript">uojHome = 'http://zhengruioi.com'</script>

		<!-- Bootstrap core CSS -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap.min.css?v=2015.5.31" />		<!-- Bootstrap theme -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap-theme.min.css?v=2015.5.31" />
		<!-- Custom styles for this template -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/uoj-theme.css?v=2.33" />		
		<!-- jQuery (necessary for Bootstrap\'s JavaScript plugins) -->
		<script src="http://zhengruioi.com/js/jquery.min.js"></script>		
		<!-- jQuery autosize -->
		<script src="http://zhengruioi.com/js/jquery.autosize.min.js"></script>		<script type="text/javascript">
			$(document).ready(function() {
				$('textarea').autosize();
			});
		</script>
		
		<!-- jQuery cookie -->
		<script src="http://zhengruioi.com/js/jquery.cookie.min.js"></script>		
		<!-- jQuery modal -->
		<script src="http://zhengruioi.com/js/jquery.modal.js"></script>		
		<!-- jQuery tag canvas -->
				
		<!-- Include all compiled plugins (below), or include individual files as needed -->
		<script src="http://zhengruioi.com/js/bootstrap.min.js?v=2015.5.31"></script>		
		<!-- Color converter -->
		<script src="http://zhengruioi.com/js/color-converter.min.js"></script>		
		<!-- uoj -->
		<script src="http://zhengruioi.com/js/uoj.js?v=2016.8.15"></script>		
		<!-- LAB -->
		<script src="http://zhengruioi.com/js/LAB.min.js"></script>
		<!-- UOJ ico -->
		<link rel="shortcut icon" href="http://zhengruioi.com/pictures/UOJ.ico" />
		
				
				
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sweetalert.min.css" />		<script src="http://zhengruioi.com/js/sweetalert.min.js"></script>
				
				
				
				<!-- MathJax -->

        <script type="text/x-mathjax-config">
			MathJax.Hub.Config({
				showProcessingMessages: false,
				tex2jax: {
					inlineMath: [["$", "$"], ["\\\\(", "\\\\)"]],
					processEscapes:true
				},
				menuSettings: {
					zoom: "Hover"
    			}
			});
		</script>
<!--		<script src="//cdn.bootcss.com/mathjax/2.6.0/MathJax.js?config=TeX-AMS_HTML"></script>-->
        <script src="/js/MathJax-2.7.9/MathJax.js?config=TeX-AMS_HTML"></script>
        <!-- <script src="https://cdn.bootcdn.net/ajax/libs/mathjax/2.6.0/config/TeX-AMS_HTML-full.js"></script> -->
				
				<!-- jquery form -->
		<script src="http://zhengruioi.com/js/jquery.form.min.js"></script>				
		
				
				
				
				
				<!-- shjs -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sh_typical.min.css" />		<script src="http://zhengruioi.com/js/sh_main.min.js"></script>		<script type="text/javascript">$(document).ready(function(){sh_highlightDocument()})</script>
				
		
		<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
		<!--[if lt IE 9]>
			<script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
			<script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
		<![endif]-->
		
		<script type="text/javascript">
		before_window_unload_message = null;
		$(window).on('beforeunload', function() {
			if (before_window_unload_message !== null) {
			    return before_window_unload_message;
			}
		});
		</script>
		
			</head>
	<body role="document">
		<div class="container theme-showcase" role="main">
						<div>
				<ul class="nav nav-pills pull-right" role="tablist">
									<li class="dropdown">
						<a href="#" data-toggle="dropdown">
							<span class="uoj-username" data-rating="1503" data-link="0">Meko</span> 						</a>
						<ul class="dropdown-menu" role="menu">
							<li role="presentation"><a href="http://zhengruioi.com/user/msg">私信&nbsp;&nbsp;</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/profile/Meko">个人信息</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/system-msg">系统消息&nbsp;&nbsp;</a></li>
													</ul>
					</li>
					<li role="presentation"><a href="http://zhengruioi.com/logout?_token=qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy">登出</a></li>
								</ul>
				<h1 class="hidden-xs"><a href="http://zhengruioi.com"><img src="http://zhengruioi.com/pictures/UOJ_small.png" alt="UOJ Logo" class="img-rounded" style="width:39px; height:39px;" /></a> Zhengrui Online Judge</h1>
				<h1 class="visible-xs">ZROI</h1>
			</div>
			
			<div class="navbar navbar-default" role="navigation">
	<div class="container-fluid">
		<div class="navbar-header">
			<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".navbar-collapse">
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
			</button>
			<a class="navbar-brand" href="http://zhengruioi.com">ZROI</a>
		</div>
		<div class="navbar-collapse collapse">
			<ul class="nav navbar-nav">
				<li><a href="/contests">比赛</a></li>
				<li><a href="/problems">题库</a></li>
				<li><a href="/submissions">提交记录</a></li>
				<li><a href="/hacks">Hack!</a></li>
				<li><a href="/blogs">博客</a></li>
				<li><a href="/faq">帮助</a></li>
				<li><a href="/rollkings">卷王榜</a></li>
<!--                <li><a href="/rollkings">--><?//= UOJLocale::get('roll kings nav') ?><!--</a></li>-->
									<li><a data-target="#switchModal" href="#" data-toggle="modal">切换</a></li>
					<div class="modal fade in" id="switchModal" tabindex="-1" aria-labelledby="switchModalLabel" aria-hidden="true" style="display: none;">
						<div class="modal-dialog" style="width: 400px;">
							<div class="modal-content">
								<div class="modal-header" style="height: 51px;">
									<h4 class="modal-title" id="switchModalLabel" style="float:left">权限选择</h4>
									<button type="button" class="close" data-dismiss="modal" aria-label="Close" style="float:right">
									<span aria-hidden="true">×</span>
									</button>
								</div>
								<form name="switchChooseForm" method="post">
									<input type="hidden" name="switchChooseFormHiddenInput" id="switchChooseFormHiddenInput" value="switch">
									<div class="modal-body">
										<div class="table-responsive">
											<table class="table table-bordered table-hover table-striped table-text-center">
												<thead><tr>
													<th><label style="margin-bottom: 2px;">
														<input type="checkbox" style="vertical-align: middle;margin-top: 0px;" id="switchChooseAll"><span style="vertical-align: middle"> 全选</span>
													</label></th>
													<th style="vertical-align: middle">团队名称</th>
												</tr></thead>
												<tbody>
													<tr><td><input id="switchCheckbox86" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="86"></td><td>金华一中2022联赛训练</td></tr><tr><td><input id="switchCheckbox98" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="98"></td><td>22暑期CD集训</td></tr><tr><td><input id="switchCheckbox103" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="103"></td><td>22noip赛前20天</td></tr>													
												</tbody>
											</table>
										</div>
									</div>
									<div class="modal-footer">
										<button type="button" class="btn btn-secondary" data-dismiss="modal">取消</button>
										<button type="submit" class="btn btn-primary">确认</button>
									</div>
								</form>
								<script type="text/javascript">
									$("#switchChooseAll").click(function() {
										if (this.checked) {
											$("#switchCheckbox86").prop("checked", true);$("#switchCheckbox98").prop("checked", true);$("#switchCheckbox103").prop("checked", true);										} else {
											$("#switchCheckbox86").prop("checked", false);$("#switchCheckbox98").prop("checked", false);$("#switchCheckbox103").prop("checked", false);										}
									})
								</script>
							</div>
						</div>
					</div>
							</ul>
		</div><!--/.nav-collapse -->
	</div>
</div>
<script type="text/javascript">
function swalConfirm(text) {
	return swal({
		html : text,
		type : 'warning',
		showCancelButton : true,
		allowOutsideClick : false,
		confirmButtonText : 'Yes',
		cancelButtonText : 'No',
		focusCancel : true
	});
}

function switchTo(id) {
	swalConfirm('您确定要切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 吗？')
	.then(function() {
		$.post('/', {
			id : id,
			type : 'switch'
		}, function(msg) {
			if (msg == 'ok') {
				swal('', '成功切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 啦', 'success')
				.then(function() {
					window.location.reload();
				});
			} else swal('', '切换失败，如有疑问请联系蔡老师', 'error');
		});
	});
}
</script>
						
			<div class="uoj-content">
<script src="/js/sec.min.js"></script><script>__canvasWM({content: 'qbYCXKLlZmD5j5oAWdfpC8ZoKdMJp7C6kOoLEzIkQ1Q='});</script>
<h1 class="page-header text-center" style="margin-bottom:0px;border-bottom:0px">#259. 18ABday5-璀璨光滑</h1>
<div class="row" style="margin-bottom:20px;border-bottom:1px">
	<div class="col-sm-2"></div>
	<div class="col-sm-8 text-center">
					<div class="btn-group" role="group" aria-label="First group">
				<button type="button" class="uoj-tag btn" disabled="">时间限制：4000 ms</button>
				<button type="button" class="uoj-tag btn" disabled="">空间限制：512 MiB</button>
				<button type="button" class="uoj-tag btn" disabled="">题目类型：传统型</button>
				<button type="button" class="uoj-tag btn" disabled="">答案检查器：文本比较</button>
			</div>
			</div>
	<div class="col-sm-2 text-right">
		<div class="uoj-click-zan-block" data-id="259" data-type="P" data-val="0" data-cnt="-32"></div>	</div>
</div>
<a role="button" class="btn btn-info pull-right" href="/problem/259/statistics"><span class="glyphicon glyphicon-stats"></span> 统计</a>
	<a role="button" class="btn btn-info pull-right" href="/download.php?type=tutorial&id=259" style="margin-right: 5px"><span class="glyphicon glyphicon-file"></span> 题解</a>

<ul class="nav nav-tabs" role="tablist">
	<li class="active"><a href="#tab-statement" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-book"></span> 描述</a></li>
	<li><a href="#tab-submit-answer" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-upload"></span> 提交</a></li>
		<li><a href="#tab-custom-test" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-console"></span> 自定义测试</a></li>
			<li><a href="/download.php?type=problem&id=259" role="button"><span class="glyphicon glyphicon-download"></span> 下发文件下载</a></li>
			</ul>
<div class="tab-content">
	<div class="tab-pane active" id="tab-statement">
				<article class="top-buffer-md"><p>作为一场快乐的模拟赛，需要一道致敬经典的题目。</p>
<p>有一张$2^n$的点的图，这个图上每个点标上了$0$到$2^n-1$之间不同的数字。记$p_i$为第$i$个点的标号，那么$u$和$v$之间连边当且仅当$p_u$与$p_v$的二进制表示恰好有一位不同。</p>
<p>现在告诉了你这张图，但是每个点的标号不见了，请找到一个字典序最小的标号方式，即先比较$p_1$，如果相同的话比较$p_2$，依次类推。</p>
<h3>输入格式</h3>
<p>第一行一个整数$T$，表示数据组数。</p>
<p>接下来一行每行一个正整数$n,m$，表示有$2^n$个点$m$条边，接下来若干行表示边，没有重边没有自环，保证有解。</p>
<p>本题读入很大，为了合理地区分算法运行的时间，本题提供一个读入优化的代码，代码见题面最下方。</p>
<p><strong>同时，请认真阅读附加代码前面的说明。</strong></p>
<h3>输出格式</h3>
<p>为了避免输出过大，对于每组数据，输出$$\left(\sum_{i=1}^{2^n} p_i * 10^{i-1} \right) \bmod 10^9+7$$</p>
<h3>样例1</h3>
<h4>样例输入</h4>
<p></p><pre>
1
2 4
1 3
1 4
3 2
4 2
</pre>
<h4>样例输出</h4>
<p></p><pre>
2130
</pre>
<h3>样例2</h3>
<p>见下载文件</p>
<h3>限制与规定</h3>
<p>对于 $20\%$ 的数据，有 $1\leq n\leq 3, \sum 2^n\leq 50$。</p>
<p>对于 $40\%$ 的数据，有 $1\leq n\leq 8, \sum 2^n\leq 10^3$。</p>
<p>对于 $60\%$ 的数据，有 $1\leq n\leq 12, \sum 2^n\leq 10^5$。</p>
<p>对于 $80\%$ 的数据，有 $1\leq n\leq 16, \sum 2^n\leq 5\times 10^5$。</p>
<p>对于 $100\%$ 的数据，有 $1\leq n\leq 18, \sum 2^n\leq 10^6, T\leq 500$。</p>
<p><strong>时间限制</strong>：$4\texttt{s}$</p>
<p><strong>空间限制</strong>：$512\texttt{MB}$</p>
<h3>下载</h3>
<p><a href="/download.php?type=problem&amp;id=259">样例数据下载</a></p>
<h3>附加代码</h3>
<p>你只要把下面的代码贴到你的代码中，然后使用read(x)读入一个整数。</p>
<p>注意它使用了fread，请不要与scanf和cin混用，本地测试的时候读入要使用文件。</p>
<p>本题不强制使用读入优化的代码，你可以自由选择用什么方式读入。无论用什么代码，请都自行测试，并且自己承担相应的风险。</p>
<p>最大的文件大概110MB左右，使用下面代码读入最大的文件不会超过0.4秒。</p>
<pre><code class="sh_cpp">namespace fastIO{ 
    #define BUF_SIZE 100000 
    #define OUT_SIZE 100000 
    #define ll long long 
    bool IOerror=0; 
    inline char nc(){ 
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE; 
        if (p1==pend){ 
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin); 
            if (pend==p1){IOerror=1;return -1;} 
        } 
        return *p1++; 
    } 
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';} 
    inline void read(int &amp;x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch&gt;='0'&amp;&amp;ch&lt;='9';ch=nc())x=x*10+ch-'0'; 
        if (sign)x=-x; 
    } 
    inline void read(ll &amp;x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch&gt;='0'&amp;&amp;ch&lt;='9';ch=nc())x=x*10+ch-'0'; 
        if (sign)x=-x; 
    } 
    #undef ll 
    #undef OUT_SIZE 
    #undef BUF_SIZE 
}; 
using namespace fastIO;</code></pre>
<p>比如下面是一个A+B的代码的例子：</p>
<pre><code class="sh_cpp">#include &lt;bits/stdc++.h&gt;
using namespace std;

namespace fastIO{ 
    // ....
}; 
using namespace fastIO; 

int a,b;
int main() {
    read(a);
    read(b);
    printf("%d\n",a+b);
}</code></pre>
</article>
	</div>
	<div class="tab-pane" id="tab-submit-answer">
		<div class="top-buffer-sm"></div>
				<form action="/problem/259" method="post" class="form-horizontal" id="form-answer" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-answer_answer"></div>
<script type="text/javascript">
$('#form-group-answer_answer').source_code_form_group('answer_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="text-center"><button type="submit" id="button-submit-answer" name="submit-answer" value="answer" class="btn btn-default">提交</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-answer').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-answer'] = "";
			$.ajax({
				url : '/problem/259',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		return ok;
	});
});
</script>	</div>
		<div class="tab-pane" id="tab-custom-test">
		<div class="top-buffer-sm"></div>
		<form action="/problem/259" method="post" class="form-horizontal" id="form-custom_test" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-custom_test_answer"></div>
<script type="text/javascript">
$('#form-group-custom_test_answer').source_code_form_group('custom_test_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="form-group" id="form-group-custom_test_input"></div>
<script type="text/javascript">
$('#form-group-custom_test_input').text_file_form_group('custom_test_input', '文本文件:input.txt');
</script><div id="div-custom_test_result"></div><div class="text-center"><button type="submit" id="button-submit-custom_test" name="submit-custom_test" value="custom_test" class="btn btn-default">运行</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-custom_test').keydown(function(e) {
		if (e.keyCode == 13 && e.ctrlKey) {
			$('#button-submit-custom_test').click();
		}
	});
	$('#form-custom_test').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-custom_test'] = "";
			$.ajax({
				url : '/problem/259',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		e.preventDefault();
		if (ok) {
			$(this).ajaxSubmit({
				beforeSubmit: function(formData) {
					formData.push({name: 'submit-custom_test', value: 'custom_test', type: 'submit'});
				},
				success : function(response_text) {custom_test_onsubmit(response_text, $('#div-custom_test_result')[0], '/problem/259?get=custom-test-status-details')}
			});
		}
	});
});
</script>	</div>
	</div>
			</div>
						<div class="uoj-footer">
				<p>
					<a href="http://zhengruioi.com/problem/259?locale=zh-cn"><img src="/pictures/lang/cn.png" alt="中文" /></a> 
					<a href="http://zhengruioi.com/problem/259?locale=en"><img src="/pictures/lang/gb.png" alt="English" /></a>
				</p>
				
				<ul class="list-inline">
					<li>Zhengrui Online Judge</li>
									</ul>
				
				<p>Server time: 2022-11-17 11:38:27 &nbsp; | &nbsp;  <a href="http://www.beian.miit.gov.cn/">浙ICP备17047493号</a></p>
			</div>
					</div>
		<!-- /container -->
	</body>
</html>
<!DOCTYPE html>
<html lang="zh-cn">
	<head>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />
				<title>18ABday5-构解巨树 - 题目 - Zhengrui Online Judge</title>
		
		<script type="text/javascript">uojHome = 'http://zhengruioi.com'</script>

		<!-- Bootstrap core CSS -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap.min.css?v=2015.5.31" />		<!-- Bootstrap theme -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap-theme.min.css?v=2015.5.31" />
		<!-- Custom styles for this template -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/uoj-theme.css?v=2.33" />		
		<!-- jQuery (necessary for Bootstrap\'s JavaScript plugins) -->
		<script src="http://zhengruioi.com/js/jquery.min.js"></script>		
		<!-- jQuery autosize -->
		<script src="http://zhengruioi.com/js/jquery.autosize.min.js"></script>		<script type="text/javascript">
			$(document).ready(function() {
				$('textarea').autosize();
			});
		</script>
		
		<!-- jQuery cookie -->
		<script src="http://zhengruioi.com/js/jquery.cookie.min.js"></script>		
		<!-- jQuery modal -->
		<script src="http://zhengruioi.com/js/jquery.modal.js"></script>		
		<!-- jQuery tag canvas -->
				
		<!-- Include all compiled plugins (below), or include individual files as needed -->
		<script src="http://zhengruioi.com/js/bootstrap.min.js?v=2015.5.31"></script>		
		<!-- Color converter -->
		<script src="http://zhengruioi.com/js/color-converter.min.js"></script>		
		<!-- uoj -->
		<script src="http://zhengruioi.com/js/uoj.js?v=2016.8.15"></script>		
		<!-- LAB -->
		<script src="http://zhengruioi.com/js/LAB.min.js"></script>
		<!-- UOJ ico -->
		<link rel="shortcut icon" href="http://zhengruioi.com/pictures/UOJ.ico" />
		
				
				
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sweetalert.min.css" />		<script src="http://zhengruioi.com/js/sweetalert.min.js"></script>
				
				
				
				<!-- MathJax -->

        <script type="text/x-mathjax-config">
			MathJax.Hub.Config({
				showProcessingMessages: false,
				tex2jax: {
					inlineMath: [["$", "$"], ["\\\\(", "\\\\)"]],
					processEscapes:true
				},
				menuSettings: {
					zoom: "Hover"
    			}
			});
		</script>
<!--		<script src="//cdn.bootcss.com/mathjax/2.6.0/MathJax.js?config=TeX-AMS_HTML"></script>-->
        <script src="/js/MathJax-2.7.9/MathJax.js?config=TeX-AMS_HTML"></script>
        <!-- <script src="https://cdn.bootcdn.net/ajax/libs/mathjax/2.6.0/config/TeX-AMS_HTML-full.js"></script> -->
				
				<!-- jquery form -->
		<script src="http://zhengruioi.com/js/jquery.form.min.js"></script>				
		
				
				
				
				
				<!-- shjs -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sh_typical.min.css" />		<script src="http://zhengruioi.com/js/sh_main.min.js"></script>		<script type="text/javascript">$(document).ready(function(){sh_highlightDocument()})</script>
				
		
		<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
		<!--[if lt IE 9]>
			<script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
			<script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
		<![endif]-->
		
		<script type="text/javascript">
		before_window_unload_message = null;
		$(window).on('beforeunload', function() {
			if (before_window_unload_message !== null) {
			    return before_window_unload_message;
			}
		});
		</script>
		
			</head>
	<body role="document">
		<div class="container theme-showcase" role="main">
						<div>
				<ul class="nav nav-pills pull-right" role="tablist">
									<li class="dropdown">
						<a href="#" data-toggle="dropdown">
							<span class="uoj-username" data-rating="1503" data-link="0">Meko</span> 						</a>
						<ul class="dropdown-menu" role="menu">
							<li role="presentation"><a href="http://zhengruioi.com/user/msg">私信&nbsp;&nbsp;</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/profile/Meko">个人信息</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/system-msg">系统消息&nbsp;&nbsp;</a></li>
													</ul>
					</li>
					<li role="presentation"><a href="http://zhengruioi.com/logout?_token=qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy">登出</a></li>
								</ul>
				<h1 class="hidden-xs"><a href="http://zhengruioi.com"><img src="http://zhengruioi.com/pictures/UOJ_small.png" alt="UOJ Logo" class="img-rounded" style="width:39px; height:39px;" /></a> Zhengrui Online Judge</h1>
				<h1 class="visible-xs">ZROI</h1>
			</div>
			
			<div class="navbar navbar-default" role="navigation">
	<div class="container-fluid">
		<div class="navbar-header">
			<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".navbar-collapse">
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
			</button>
			<a class="navbar-brand" href="http://zhengruioi.com">ZROI</a>
		</div>
		<div class="navbar-collapse collapse">
			<ul class="nav navbar-nav">
				<li><a href="/contests">比赛</a></li>
				<li><a href="/problems">题库</a></li>
				<li><a href="/submissions">提交记录</a></li>
				<li><a href="/hacks">Hack!</a></li>
				<li><a href="/blogs">博客</a></li>
				<li><a href="/faq">帮助</a></li>
				<li><a href="/rollkings">卷王榜</a></li>
<!--                <li><a href="/rollkings">--><?//= UOJLocale::get('roll kings nav') ?><!--</a></li>-->
									<li><a data-target="#switchModal" href="#" data-toggle="modal">切换</a></li>
					<div class="modal fade in" id="switchModal" tabindex="-1" aria-labelledby="switchModalLabel" aria-hidden="true" style="display: none;">
						<div class="modal-dialog" style="width: 400px;">
							<div class="modal-content">
								<div class="modal-header" style="height: 51px;">
									<h4 class="modal-title" id="switchModalLabel" style="float:left">权限选择</h4>
									<button type="button" class="close" data-dismiss="modal" aria-label="Close" style="float:right">
									<span aria-hidden="true">×</span>
									</button>
								</div>
								<form name="switchChooseForm" method="post">
									<input type="hidden" name="switchChooseFormHiddenInput" id="switchChooseFormHiddenInput" value="switch">
									<div class="modal-body">
										<div class="table-responsive">
											<table class="table table-bordered table-hover table-striped table-text-center">
												<thead><tr>
													<th><label style="margin-bottom: 2px;">
														<input type="checkbox" style="vertical-align: middle;margin-top: 0px;" id="switchChooseAll"><span style="vertical-align: middle"> 全选</span>
													</label></th>
													<th style="vertical-align: middle">团队名称</th>
												</tr></thead>
												<tbody>
													<tr><td><input id="switchCheckbox86" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="86"></td><td>金华一中2022联赛训练</td></tr><tr><td><input id="switchCheckbox98" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="98"></td><td>22暑期CD集训</td></tr><tr><td><input id="switchCheckbox103" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="103"></td><td>22noip赛前20天</td></tr>													
												</tbody>
											</table>
										</div>
									</div>
									<div class="modal-footer">
										<button type="button" class="btn btn-secondary" data-dismiss="modal">取消</button>
										<button type="submit" class="btn btn-primary">确认</button>
									</div>
								</form>
								<script type="text/javascript">
									$("#switchChooseAll").click(function() {
										if (this.checked) {
											$("#switchCheckbox86").prop("checked", true);$("#switchCheckbox98").prop("checked", true);$("#switchCheckbox103").prop("checked", true);										} else {
											$("#switchCheckbox86").prop("checked", false);$("#switchCheckbox98").prop("checked", false);$("#switchCheckbox103").prop("checked", false);										}
									})
								</script>
							</div>
						</div>
					</div>
							</ul>
		</div><!--/.nav-collapse -->
	</div>
</div>
<script type="text/javascript">
function swalConfirm(text) {
	return swal({
		html : text,
		type : 'warning',
		showCancelButton : true,
		allowOutsideClick : false,
		confirmButtonText : 'Yes',
		cancelButtonText : 'No',
		focusCancel : true
	});
}

function switchTo(id) {
	swalConfirm('您确定要切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 吗？')
	.then(function() {
		$.post('/', {
			id : id,
			type : 'switch'
		}, function(msg) {
			if (msg == 'ok') {
				swal('', '成功切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 啦', 'success')
				.then(function() {
					window.location.reload();
				});
			} else swal('', '切换失败，如有疑问请联系蔡老师', 'error');
		});
	});
}
</script>
						
			<div class="uoj-content">
<script src="/js/sec.min.js"></script><script>__canvasWM({content: 'qbYCXKLlZmD5j5oAWdfpC69I2DJYzSKi4H1X7TGKu9Y='});</script>
<h1 class="page-header text-center" style="margin-bottom:0px;border-bottom:0px">#260. 18ABday5-构解巨树</h1>
<div class="row" style="margin-bottom:20px;border-bottom:1px">
	<div class="col-sm-2"></div>
	<div class="col-sm-8 text-center">
					<div class="btn-group" role="group" aria-label="First group">
				<button type="button" class="uoj-tag btn" disabled="">时间限制：2000 ms</button>
				<button type="button" class="uoj-tag btn" disabled="">空间限制：512 MiB</button>
				<button type="button" class="uoj-tag btn" disabled="">题目类型：传统型</button>
				<button type="button" class="uoj-tag btn" disabled="">答案检查器：文本比较</button>
			</div>
			</div>
	<div class="col-sm-2 text-right">
		<div class="uoj-click-zan-block" data-id="260" data-type="P" data-val="0" data-cnt="-34"></div>	</div>
</div>
<a role="button" class="btn btn-info pull-right" href="/problem/260/statistics"><span class="glyphicon glyphicon-stats"></span> 统计</a>
	<a role="button" class="btn btn-info pull-right" href="/download.php?type=tutorial&id=260" style="margin-right: 5px"><span class="glyphicon glyphicon-file"></span> 题解</a>

<ul class="nav nav-tabs" role="tablist">
	<li class="active"><a href="#tab-statement" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-book"></span> 描述</a></li>
	<li><a href="#tab-submit-answer" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-upload"></span> 提交</a></li>
		<li><a href="#tab-custom-test" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-console"></span> 自定义测试</a></li>
			<li><a href="/download.php?type=problem&id=260" role="button"><span class="glyphicon glyphicon-download"></span> 下发文件下载</a></li>
			</ul>
<div class="tab-content">
	<div class="tab-pane active" id="tab-statement">
				<article class="top-buffer-md"><p>作为一场快乐的模拟赛，需要一道简单的模板题。</p>
<p>这是一道树套树的模板题。</p>
<p>你有一棵$n$个点树$T$，然后你把它复制了$m$遍，然后在这$m$棵树之间又加了$m-1$条边，变成了一棵新的有$nm$个点的巨树$T_2$。</p>
<p>求$T_2$中所有点对的距离和，由于答案很大，对$10^9+7$取模。</p>
<h3>输入格式</h3>
<p>每组数据第一行两个正整数$n,m$。</p>
<p>接下来$n-1$行，每行两个正整数$u, v(1\leq u, v\leq n)$表示$T$中的一条边。</p>
<p>接下来$m-1$行，每行四个正整数$a, b, u ,v(1\leq a, b\leq m, 1\leq u,v \leq n)$表示$T$的第$a$份拷贝中的$u$点与$T$的第$b$份拷贝中的$v$点之间连了一条边。</p>
<p>保证$T$与$T_2$都是一棵树。</p>
<h3>输出格式</h3>
<p>对于每组数据，输出一行表示答案。</p>
<h3>样例1</h3>
<h4>样例输入</h4>
<pre>
3 3
1 2
2 3
1 2 2 1
1 3 3 2
</pre>

<h4>样例输出</h4>
<pre>
102
</pre>

<h3>样例2</h3>
<p>见下载文件</p>
<h3>限制与规定</h3>
<p>对于 $20\%$ 的数据，有 $1\leq n,m\leq 1000$。</p>
<p>对于另外 $20\%$ 的数据，有 $1\leq n,m\leq 10^5$，保证$a = 1$。</p>
<p>对于另外 $30\%$ 的数据，有 $1\leq n,m\leq 10^5$，保证$T$是随机生成的。</p>
<p>对于 $100\%$ 的数据，有 $1\leq n,m \leq 10^5$。</p>
<p><strong>时间限制</strong>：$2\texttt{s}$</p>
<p><strong>空间限制</strong>：$512\texttt{MB}$</p>
<h3>下载</h3>
<p><a href="/download.php?type=problem&amp;id=260">样例数据下载</a></p>
</article>
	</div>
	<div class="tab-pane" id="tab-submit-answer">
		<div class="top-buffer-sm"></div>
				<form action="/problem/260" method="post" class="form-horizontal" id="form-answer" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-answer_answer"></div>
<script type="text/javascript">
$('#form-group-answer_answer').source_code_form_group('answer_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="text-center"><button type="submit" id="button-submit-answer" name="submit-answer" value="answer" class="btn btn-default">提交</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-answer').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-answer'] = "";
			$.ajax({
				url : '/problem/260',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		return ok;
	});
});
</script>	</div>
		<div class="tab-pane" id="tab-custom-test">
		<div class="top-buffer-sm"></div>
		<form action="/problem/260" method="post" class="form-horizontal" id="form-custom_test" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-custom_test_answer"></div>
<script type="text/javascript">
$('#form-group-custom_test_answer').source_code_form_group('custom_test_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="form-group" id="form-group-custom_test_input"></div>
<script type="text/javascript">
$('#form-group-custom_test_input').text_file_form_group('custom_test_input', '文本文件:input.txt');
</script><div id="div-custom_test_result"></div><div class="text-center"><button type="submit" id="button-submit-custom_test" name="submit-custom_test" value="custom_test" class="btn btn-default">运行</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-custom_test').keydown(function(e) {
		if (e.keyCode == 13 && e.ctrlKey) {
			$('#button-submit-custom_test').click();
		}
	});
	$('#form-custom_test').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-custom_test'] = "";
			$.ajax({
				url : '/problem/260',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		e.preventDefault();
		if (ok) {
			$(this).ajaxSubmit({
				beforeSubmit: function(formData) {
					formData.push({name: 'submit-custom_test', value: 'custom_test', type: 'submit'});
				},
				success : function(response_text) {custom_test_onsubmit(response_text, $('#div-custom_test_result')[0], '/problem/260?get=custom-test-status-details')}
			});
		}
	});
});
</script>	</div>
	</div>
			</div>
						<div class="uoj-footer">
				<p>
					<a href="http://zhengruioi.com/problem/260?locale=zh-cn"><img src="/pictures/lang/cn.png" alt="中文" /></a> 
					<a href="http://zhengruioi.com/problem/260?locale=en"><img src="/pictures/lang/gb.png" alt="English" /></a>
				</p>
				
				<ul class="list-inline">
					<li>Zhengrui Online Judge</li>
									</ul>
				
				<p>Server time: 2022-11-17 11:38:27 &nbsp; | &nbsp;  <a href="http://www.beian.miit.gov.cn/">浙ICP备17047493号</a></p>
			</div>
					</div>
		<!-- /container -->
	</body>
</html>
<!DOCTYPE html>
<html lang="zh-cn">
	<head>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />
				<title>线段树什么的最讨厌了 - 题目 - Zhengrui Online Judge</title>
		
		<script type="text/javascript">uojHome = 'http://zhengruioi.com'</script>

		<!-- Bootstrap core CSS -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap.min.css?v=2015.5.31" />		<!-- Bootstrap theme -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap-theme.min.css?v=2015.5.31" />
		<!-- Custom styles for this template -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/uoj-theme.css?v=2.33" />		
		<!-- jQuery (necessary for Bootstrap\'s JavaScript plugins) -->
		<script src="http://zhengruioi.com/js/jquery.min.js"></script>		
		<!-- jQuery autosize -->
		<script src="http://zhengruioi.com/js/jquery.autosize.min.js"></script>		<script type="text/javascript">
			$(document).ready(function() {
				$('textarea').autosize();
			});
		</script>
		
		<!-- jQuery cookie -->
		<script src="http://zhengruioi.com/js/jquery.cookie.min.js"></script>		
		<!-- jQuery modal -->
		<script src="http://zhengruioi.com/js/jquery.modal.js"></script>		
		<!-- jQuery tag canvas -->
				
		<!-- Include all compiled plugins (below), or include individual files as needed -->
		<script src="http://zhengruioi.com/js/bootstrap.min.js?v=2015.5.31"></script>		
		<!-- Color converter -->
		<script src="http://zhengruioi.com/js/color-converter.min.js"></script>		
		<!-- uoj -->
		<script src="http://zhengruioi.com/js/uoj.js?v=2016.8.15"></script>		
		<!-- LAB -->
		<script src="http://zhengruioi.com/js/LAB.min.js"></script>
		<!-- UOJ ico -->
		<link rel="shortcut icon" href="http://zhengruioi.com/pictures/UOJ.ico" />
		
				
				
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sweetalert.min.css" />		<script src="http://zhengruioi.com/js/sweetalert.min.js"></script>
				
				
				
				<!-- MathJax -->

        <script type="text/x-mathjax-config">
			MathJax.Hub.Config({
				showProcessingMessages: false,
				tex2jax: {
					inlineMath: [["$", "$"], ["\\\\(", "\\\\)"]],
					processEscapes:true
				},
				menuSettings: {
					zoom: "Hover"
    			}
			});
		</script>
<!--		<script src="//cdn.bootcss.com/mathjax/2.6.0/MathJax.js?config=TeX-AMS_HTML"></script>-->
        <script src="/js/MathJax-2.7.9/MathJax.js?config=TeX-AMS_HTML"></script>
        <!-- <script src="https://cdn.bootcdn.net/ajax/libs/mathjax/2.6.0/config/TeX-AMS_HTML-full.js"></script> -->
				
				<!-- jquery form -->
		<script src="http://zhengruioi.com/js/jquery.form.min.js"></script>				
		
				
				
				
				
				<!-- shjs -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sh_typical.min.css" />		<script src="http://zhengruioi.com/js/sh_main.min.js"></script>		<script type="text/javascript">$(document).ready(function(){sh_highlightDocument()})</script>
				
		
		<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
		<!--[if lt IE 9]>
			<script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
			<script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
		<![endif]-->
		
		<script type="text/javascript">
		before_window_unload_message = null;
		$(window).on('beforeunload', function() {
			if (before_window_unload_message !== null) {
			    return before_window_unload_message;
			}
		});
		</script>
		
			</head>
	<body role="document">
		<div class="container theme-showcase" role="main">
						<div>
				<ul class="nav nav-pills pull-right" role="tablist">
									<li class="dropdown">
						<a href="#" data-toggle="dropdown">
							<span class="uoj-username" data-rating="1503" data-link="0">Meko</span> 						</a>
						<ul class="dropdown-menu" role="menu">
							<li role="presentation"><a href="http://zhengruioi.com/user/msg">私信&nbsp;&nbsp;</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/profile/Meko">个人信息</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/system-msg">系统消息&nbsp;&nbsp;</a></li>
													</ul>
					</li>
					<li role="presentation"><a href="http://zhengruioi.com/logout?_token=qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy">登出</a></li>
								</ul>
				<h1 class="hidden-xs"><a href="http://zhengruioi.com"><img src="http://zhengruioi.com/pictures/UOJ_small.png" alt="UOJ Logo" class="img-rounded" style="width:39px; height:39px;" /></a> Zhengrui Online Judge</h1>
				<h1 class="visible-xs">ZROI</h1>
			</div>
			
			<div class="navbar navbar-default" role="navigation">
	<div class="container-fluid">
		<div class="navbar-header">
			<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".navbar-collapse">
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
			</button>
			<a class="navbar-brand" href="http://zhengruioi.com">ZROI</a>
		</div>
		<div class="navbar-collapse collapse">
			<ul class="nav navbar-nav">
				<li><a href="/contests">比赛</a></li>
				<li><a href="/problems">题库</a></li>
				<li><a href="/submissions">提交记录</a></li>
				<li><a href="/hacks">Hack!</a></li>
				<li><a href="/blogs">博客</a></li>
				<li><a href="/faq">帮助</a></li>
				<li><a href="/rollkings">卷王榜</a></li>
<!--                <li><a href="/rollkings">--><?//= UOJLocale::get('roll kings nav') ?><!--</a></li>-->
									<li><a data-target="#switchModal" href="#" data-toggle="modal">切换</a></li>
					<div class="modal fade in" id="switchModal" tabindex="-1" aria-labelledby="switchModalLabel" aria-hidden="true" style="display: none;">
						<div class="modal-dialog" style="width: 400px;">
							<div class="modal-content">
								<div class="modal-header" style="height: 51px;">
									<h4 class="modal-title" id="switchModalLabel" style="float:left">权限选择</h4>
									<button type="button" class="close" data-dismiss="modal" aria-label="Close" style="float:right">
									<span aria-hidden="true">×</span>
									</button>
								</div>
								<form name="switchChooseForm" method="post">
									<input type="hidden" name="switchChooseFormHiddenInput" id="switchChooseFormHiddenInput" value="switch">
									<div class="modal-body">
										<div class="table-responsive">
											<table class="table table-bordered table-hover table-striped table-text-center">
												<thead><tr>
													<th><label style="margin-bottom: 2px;">
														<input type="checkbox" style="vertical-align: middle;margin-top: 0px;" id="switchChooseAll"><span style="vertical-align: middle"> 全选</span>
													</label></th>
													<th style="vertical-align: middle">团队名称</th>
												</tr></thead>
												<tbody>
													<tr><td><input id="switchCheckbox86" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="86"></td><td>金华一中2022联赛训练</td></tr><tr><td><input id="switchCheckbox98" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="98"></td><td>22暑期CD集训</td></tr><tr><td><input id="switchCheckbox103" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="103"></td><td>22noip赛前20天</td></tr>													
												</tbody>
											</table>
										</div>
									</div>
									<div class="modal-footer">
										<button type="button" class="btn btn-secondary" data-dismiss="modal">取消</button>
										<button type="submit" class="btn btn-primary">确认</button>
									</div>
								</form>
								<script type="text/javascript">
									$("#switchChooseAll").click(function() {
										if (this.checked) {
											$("#switchCheckbox86").prop("checked", true);$("#switchCheckbox98").prop("checked", true);$("#switchCheckbox103").prop("checked", true);										} else {
											$("#switchCheckbox86").prop("checked", false);$("#switchCheckbox98").prop("checked", false);$("#switchCheckbox103").prop("checked", false);										}
									})
								</script>
							</div>
						</div>
					</div>
							</ul>
		</div><!--/.nav-collapse -->
	</div>
</div>
<script type="text/javascript">
function swalConfirm(text) {
	return swal({
		html : text,
		type : 'warning',
		showCancelButton : true,
		allowOutsideClick : false,
		confirmButtonText : 'Yes',
		cancelButtonText : 'No',
		focusCancel : true
	});
}

function switchTo(id) {
	swalConfirm('您确定要切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 吗？')
	.then(function() {
		$.post('/', {
			id : id,
			type : 'switch'
		}, function(msg) {
			if (msg == 'ok') {
				swal('', '成功切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 啦', 'success')
				.then(function() {
					window.location.reload();
				});
			} else swal('', '切换失败，如有疑问请联系蔡老师', 'error');
		});
	});
}
</script>
						
			<div class="uoj-content">
<script src="/js/sec.min.js"></script><script>__canvasWM({content: 'qbYCXKLlZmD5j5oAWdfpC69I2DJYzSKi4H1X7TGKu9Y='});</script>
<h1 class="page-header text-center" style="margin-bottom:0px;border-bottom:0px">#456. 线段树什么的最讨厌了</h1>
<div class="row" style="margin-bottom:20px;border-bottom:1px">
	<div class="col-sm-2"></div>
	<div class="col-sm-8 text-center">
					<div class="btn-group" role="group" aria-label="First group">
				<button type="button" class="uoj-tag btn" disabled="">时间限制：1000 ms</button>
				<button type="button" class="uoj-tag btn" disabled="">空间限制：512 MiB</button>
				<button type="button" class="uoj-tag btn" disabled="">题目类型：传统型</button>
				<button type="button" class="uoj-tag btn" disabled="">答案检查器：文本比较</button>
			</div>
			</div>
	<div class="col-sm-2 text-right">
		<div class="uoj-click-zan-block" data-id="456" data-type="P" data-val="0" data-cnt="11"></div>	</div>
</div>
<a role="button" class="btn btn-info pull-right" href="/problem/456/statistics"><span class="glyphicon glyphicon-stats"></span> 统计</a>
	<a role="button" class="btn btn-info pull-right" href="/download.php?type=tutorial&id=456" style="margin-right: 5px"><span class="glyphicon glyphicon-file"></span> 题解</a>

<ul class="nav nav-tabs" role="tablist">
	<li class="active"><a href="#tab-statement" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-book"></span> 描述</a></li>
	<li><a href="#tab-submit-answer" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-upload"></span> 提交</a></li>
		<li><a href="#tab-custom-test" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-console"></span> 自定义测试</a></li>
			<li><a href="/download.php?type=problem&id=456" role="button"><span class="glyphicon glyphicon-download"></span> 下发文件下载</a></li>
			</ul>
<div class="tab-content">
	<div class="tab-pane active" id="tab-statement">
		<!--			<iframe src="/static/u8jDXvILMzk3/1.pdf" width="100%" height="700px"></iframe>-->
			<iframe src="/download.php?type=statement&id=456" width="100%" height="700px"></iframe>
				<article class="top-buffer-md"><p>时间限制 : 1s</p>
<p>空间限制 : 512M</p>
<p><a href="http://zhengruioi.com/download.php?type=problem&amp;id=456">样例下载</a></p>
</article>
	</div>
	<div class="tab-pane" id="tab-submit-answer">
		<div class="top-buffer-sm"></div>
				<form action="/problem/456" method="post" class="form-horizontal" id="form-answer" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-answer_answer"></div>
<script type="text/javascript">
$('#form-group-answer_answer').source_code_form_group('answer_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="text-center"><button type="submit" id="button-submit-answer" name="submit-answer" value="answer" class="btn btn-default">提交</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-answer').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-answer'] = "";
			$.ajax({
				url : '/problem/456',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		return ok;
	});
});
</script>	</div>
		<div class="tab-pane" id="tab-custom-test">
		<div class="top-buffer-sm"></div>
		<form action="/problem/456" method="post" class="form-horizontal" id="form-custom_test" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-custom_test_answer"></div>
<script type="text/javascript">
$('#form-group-custom_test_answer').source_code_form_group('custom_test_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="form-group" id="form-group-custom_test_input"></div>
<script type="text/javascript">
$('#form-group-custom_test_input').text_file_form_group('custom_test_input', '文本文件:input.txt');
</script><div id="div-custom_test_result"></div><div class="text-center"><button type="submit" id="button-submit-custom_test" name="submit-custom_test" value="custom_test" class="btn btn-default">运行</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-custom_test').keydown(function(e) {
		if (e.keyCode == 13 && e.ctrlKey) {
			$('#button-submit-custom_test').click();
		}
	});
	$('#form-custom_test').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-custom_test'] = "";
			$.ajax({
				url : '/problem/456',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		e.preventDefault();
		if (ok) {
			$(this).ajaxSubmit({
				beforeSubmit: function(formData) {
					formData.push({name: 'submit-custom_test', value: 'custom_test', type: 'submit'});
				},
				success : function(response_text) {custom_test_onsubmit(response_text, $('#div-custom_test_result')[0], '/problem/456?get=custom-test-status-details')}
			});
		}
	});
});
</script>	</div>
	</div>
			</div>
						<div class="uoj-footer">
				<p>
					<a href="http://zhengruioi.com/problem/456?locale=zh-cn"><img src="/pictures/lang/cn.png" alt="中文" /></a> 
					<a href="http://zhengruioi.com/problem/456?locale=en"><img src="/pictures/lang/gb.png" alt="English" /></a>
				</p>
				
				<ul class="list-inline">
					<li>Zhengrui Online Judge</li>
									</ul>
				
				<p>Server time: 2022-11-17 11:38:28 &nbsp; | &nbsp;  <a href="http://www.beian.miit.gov.cn/">浙ICP备17047493号</a></p>
			</div>
					</div>
		<!-- /container -->
	</body>
</html>
<!DOCTYPE html>
<html lang="zh-cn">
	<head>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />
				<title>已经没有什么好害怕的了 - 题目 - Zhengrui Online Judge</title>
		
		<script type="text/javascript">uojHome = 'http://zhengruioi.com'</script>

		<!-- Bootstrap core CSS -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap.min.css?v=2015.5.31" />		<!-- Bootstrap theme -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap-theme.min.css?v=2015.5.31" />
		<!-- Custom styles for this template -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/uoj-theme.css?v=2.33" />		
		<!-- jQuery (necessary for Bootstrap\'s JavaScript plugins) -->
		<script src="http://zhengruioi.com/js/jquery.min.js"></script>		
		<!-- jQuery autosize -->
		<script src="http://zhengruioi.com/js/jquery.autosize.min.js"></script>		<script type="text/javascript">
			$(document).ready(function() {
				$('textarea').autosize();
			});
		</script>
		
		<!-- jQuery cookie -->
		<script src="http://zhengruioi.com/js/jquery.cookie.min.js"></script>		
		<!-- jQuery modal -->
		<script src="http://zhengruioi.com/js/jquery.modal.js"></script>		
		<!-- jQuery tag canvas -->
				
		<!-- Include all compiled plugins (below), or include individual files as needed -->
		<script src="http://zhengruioi.com/js/bootstrap.min.js?v=2015.5.31"></script>		
		<!-- Color converter -->
		<script src="http://zhengruioi.com/js/color-converter.min.js"></script>		
		<!-- uoj -->
		<script src="http://zhengruioi.com/js/uoj.js?v=2016.8.15"></script>		
		<!-- LAB -->
		<script src="http://zhengruioi.com/js/LAB.min.js"></script>
		<!-- UOJ ico -->
		<link rel="shortcut icon" href="http://zhengruioi.com/pictures/UOJ.ico" />
		
				
				
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sweetalert.min.css" />		<script src="http://zhengruioi.com/js/sweetalert.min.js"></script>
				
				
				
				<!-- MathJax -->

        <script type="text/x-mathjax-config">
			MathJax.Hub.Config({
				showProcessingMessages: false,
				tex2jax: {
					inlineMath: [["$", "$"], ["\\\\(", "\\\\)"]],
					processEscapes:true
				},
				menuSettings: {
					zoom: "Hover"
    			}
			});
		</script>
<!--		<script src="//cdn.bootcss.com/mathjax/2.6.0/MathJax.js?config=TeX-AMS_HTML"></script>-->
        <script src="/js/MathJax-2.7.9/MathJax.js?config=TeX-AMS_HTML"></script>
        <!-- <script src="https://cdn.bootcdn.net/ajax/libs/mathjax/2.6.0/config/TeX-AMS_HTML-full.js"></script> -->
				
				<!-- jquery form -->
		<script src="http://zhengruioi.com/js/jquery.form.min.js"></script>				
		
				
				
				
				
				<!-- shjs -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sh_typical.min.css" />		<script src="http://zhengruioi.com/js/sh_main.min.js"></script>		<script type="text/javascript">$(document).ready(function(){sh_highlightDocument()})</script>
				
		
		<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
		<!--[if lt IE 9]>
			<script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
			<script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
		<![endif]-->
		
		<script type="text/javascript">
		before_window_unload_message = null;
		$(window).on('beforeunload', function() {
			if (before_window_unload_message !== null) {
			    return before_window_unload_message;
			}
		});
		</script>
		
			</head>
	<body role="document">
		<div class="container theme-showcase" role="main">
						<div>
				<ul class="nav nav-pills pull-right" role="tablist">
									<li class="dropdown">
						<a href="#" data-toggle="dropdown">
							<span class="uoj-username" data-rating="1503" data-link="0">Meko</span> 						</a>
						<ul class="dropdown-menu" role="menu">
							<li role="presentation"><a href="http://zhengruioi.com/user/msg">私信&nbsp;&nbsp;</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/profile/Meko">个人信息</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/system-msg">系统消息&nbsp;&nbsp;</a></li>
													</ul>
					</li>
					<li role="presentation"><a href="http://zhengruioi.com/logout?_token=qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy">登出</a></li>
								</ul>
				<h1 class="hidden-xs"><a href="http://zhengruioi.com"><img src="http://zhengruioi.com/pictures/UOJ_small.png" alt="UOJ Logo" class="img-rounded" style="width:39px; height:39px;" /></a> Zhengrui Online Judge</h1>
				<h1 class="visible-xs">ZROI</h1>
			</div>
			
			<div class="navbar navbar-default" role="navigation">
	<div class="container-fluid">
		<div class="navbar-header">
			<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".navbar-collapse">
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
			</button>
			<a class="navbar-brand" href="http://zhengruioi.com">ZROI</a>
		</div>
		<div class="navbar-collapse collapse">
			<ul class="nav navbar-nav">
				<li><a href="/contests">比赛</a></li>
				<li><a href="/problems">题库</a></li>
				<li><a href="/submissions">提交记录</a></li>
				<li><a href="/hacks">Hack!</a></li>
				<li><a href="/blogs">博客</a></li>
				<li><a href="/faq">帮助</a></li>
				<li><a href="/rollkings">卷王榜</a></li>
<!--                <li><a href="/rollkings">--><?//= UOJLocale::get('roll kings nav') ?><!--</a></li>-->
									<li><a data-target="#switchModal" href="#" data-toggle="modal">切换</a></li>
					<div class="modal fade in" id="switchModal" tabindex="-1" aria-labelledby="switchModalLabel" aria-hidden="true" style="display: none;">
						<div class="modal-dialog" style="width: 400px;">
							<div class="modal-content">
								<div class="modal-header" style="height: 51px;">
									<h4 class="modal-title" id="switchModalLabel" style="float:left">权限选择</h4>
									<button type="button" class="close" data-dismiss="modal" aria-label="Close" style="float:right">
									<span aria-hidden="true">×</span>
									</button>
								</div>
								<form name="switchChooseForm" method="post">
									<input type="hidden" name="switchChooseFormHiddenInput" id="switchChooseFormHiddenInput" value="switch">
									<div class="modal-body">
										<div class="table-responsive">
											<table class="table table-bordered table-hover table-striped table-text-center">
												<thead><tr>
													<th><label style="margin-bottom: 2px;">
														<input type="checkbox" style="vertical-align: middle;margin-top: 0px;" id="switchChooseAll"><span style="vertical-align: middle"> 全选</span>
													</label></th>
													<th style="vertical-align: middle">团队名称</th>
												</tr></thead>
												<tbody>
													<tr><td><input id="switchCheckbox86" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="86"></td><td>金华一中2022联赛训练</td></tr><tr><td><input id="switchCheckbox98" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="98"></td><td>22暑期CD集训</td></tr><tr><td><input id="switchCheckbox103" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="103"></td><td>22noip赛前20天</td></tr>													
												</tbody>
											</table>
										</div>
									</div>
									<div class="modal-footer">
										<button type="button" class="btn btn-secondary" data-dismiss="modal">取消</button>
										<button type="submit" class="btn btn-primary">确认</button>
									</div>
								</form>
								<script type="text/javascript">
									$("#switchChooseAll").click(function() {
										if (this.checked) {
											$("#switchCheckbox86").prop("checked", true);$("#switchCheckbox98").prop("checked", true);$("#switchCheckbox103").prop("checked", true);										} else {
											$("#switchCheckbox86").prop("checked", false);$("#switchCheckbox98").prop("checked", false);$("#switchCheckbox103").prop("checked", false);										}
									})
								</script>
							</div>
						</div>
					</div>
							</ul>
		</div><!--/.nav-collapse -->
	</div>
</div>
<script type="text/javascript">
function swalConfirm(text) {
	return swal({
		html : text,
		type : 'warning',
		showCancelButton : true,
		allowOutsideClick : false,
		confirmButtonText : 'Yes',
		cancelButtonText : 'No',
		focusCancel : true
	});
}

function switchTo(id) {
	swalConfirm('您确定要切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 吗？')
	.then(function() {
		$.post('/', {
			id : id,
			type : 'switch'
		}, function(msg) {
			if (msg == 'ok') {
				swal('', '成功切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 啦', 'success')
				.then(function() {
					window.location.reload();
				});
			} else swal('', '切换失败，如有疑问请联系蔡老师', 'error');
		});
	});
}
</script>
						
			<div class="uoj-content">
<script src="/js/sec.min.js"></script><script>__canvasWM({content: 'qbYCXKLlZmD5j5oAWdfpC69I2DJYzSKi4H1X7TGKu9Y='});</script>
<h1 class="page-header text-center" style="margin-bottom:0px;border-bottom:0px">#457. 已经没有什么好害怕的了</h1>
<div class="row" style="margin-bottom:20px;border-bottom:1px">
	<div class="col-sm-2"></div>
	<div class="col-sm-8 text-center">
					<div class="btn-group" role="group" aria-label="First group">
				<button type="button" class="uoj-tag btn" disabled="">时间限制：1000 ms</button>
				<button type="button" class="uoj-tag btn" disabled="">空间限制：512 MiB</button>
				<button type="button" class="uoj-tag btn" disabled="">题目类型：传统型</button>
				<button type="button" class="uoj-tag btn" disabled="">答案检查器：文本比较</button>
			</div>
			</div>
	<div class="col-sm-2 text-right">
		<div class="uoj-click-zan-block" data-id="457" data-type="P" data-val="-1" data-cnt="11"></div>	</div>
</div>
<a role="button" class="btn btn-info pull-right" href="/problem/457/statistics"><span class="glyphicon glyphicon-stats"></span> 统计</a>
	<a role="button" class="btn btn-info pull-right" href="/download.php?type=tutorial&id=457" style="margin-right: 5px"><span class="glyphicon glyphicon-file"></span> 题解</a>

<ul class="nav nav-tabs" role="tablist">
	<li class="active"><a href="#tab-statement" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-book"></span> 描述</a></li>
	<li><a href="#tab-submit-answer" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-upload"></span> 提交</a></li>
		<li><a href="#tab-custom-test" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-console"></span> 自定义测试</a></li>
			<li><a href="/download.php?type=problem&id=457" role="button"><span class="glyphicon glyphicon-download"></span> 下发文件下载</a></li>
			</ul>
<div class="tab-content">
	<div class="tab-pane active" id="tab-statement">
		<!--			<iframe src="/static/nTyJVxx4gUrK/2.pdf" width="100%" height="700px"></iframe>-->
			<iframe src="/download.php?type=statement&id=457" width="100%" height="700px"></iframe>
				<article class="top-buffer-md"><p>时间限制 : 1s</p>
<p>空间限制 : 512M</p>
<p><a href="http://zhengruioi.com/download.php?type=problem&amp;id=457">样例下载</a></p>
</article>
	</div>
	<div class="tab-pane" id="tab-submit-answer">
		<div class="top-buffer-sm"></div>
				<form action="/problem/457" method="post" class="form-horizontal" id="form-answer" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-answer_answer"></div>
<script type="text/javascript">
$('#form-group-answer_answer').source_code_form_group('answer_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="text-center"><button type="submit" id="button-submit-answer" name="submit-answer" value="answer" class="btn btn-default">提交</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-answer').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-answer'] = "";
			$.ajax({
				url : '/problem/457',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		return ok;
	});
});
</script>	</div>
		<div class="tab-pane" id="tab-custom-test">
		<div class="top-buffer-sm"></div>
		<form action="/problem/457" method="post" class="form-horizontal" id="form-custom_test" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-custom_test_answer"></div>
<script type="text/javascript">
$('#form-group-custom_test_answer').source_code_form_group('custom_test_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="form-group" id="form-group-custom_test_input"></div>
<script type="text/javascript">
$('#form-group-custom_test_input').text_file_form_group('custom_test_input', '文本文件:input.txt');
</script><div id="div-custom_test_result"></div><div class="text-center"><button type="submit" id="button-submit-custom_test" name="submit-custom_test" value="custom_test" class="btn btn-default">运行</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-custom_test').keydown(function(e) {
		if (e.keyCode == 13 && e.ctrlKey) {
			$('#button-submit-custom_test').click();
		}
	});
	$('#form-custom_test').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-custom_test'] = "";
			$.ajax({
				url : '/problem/457',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		e.preventDefault();
		if (ok) {
			$(this).ajaxSubmit({
				beforeSubmit: function(formData) {
					formData.push({name: 'submit-custom_test', value: 'custom_test', type: 'submit'});
				},
				success : function(response_text) {custom_test_onsubmit(response_text, $('#div-custom_test_result')[0], '/problem/457?get=custom-test-status-details')}
			});
		}
	});
});
</script>	</div>
	</div>
			</div>
						<div class="uoj-footer">
				<p>
					<a href="http://zhengruioi.com/problem/457?locale=zh-cn"><img src="/pictures/lang/cn.png" alt="中文" /></a> 
					<a href="http://zhengruioi.com/problem/457?locale=en"><img src="/pictures/lang/gb.png" alt="English" /></a>
				</p>
				
				<ul class="list-inline">
					<li>Zhengrui Online Judge</li>
									</ul>
				
				<p>Server time: 2022-11-17 11:38:28 &nbsp; | &nbsp;  <a href="http://www.beian.miit.gov.cn/">浙ICP备17047493号</a></p>
			</div>
					</div>
		<!-- /container -->
	</body>
</html>
<!DOCTYPE html>
<html lang="zh-cn">
	<head>
		<meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />
				<title>我才不是萝莉控呢 - 题目 - Zhengrui Online Judge</title>
		
		<script type="text/javascript">uojHome = 'http://zhengruioi.com'</script>

		<!-- Bootstrap core CSS -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap.min.css?v=2015.5.31" />		<!-- Bootstrap theme -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/bootstrap-theme.min.css?v=2015.5.31" />
		<!-- Custom styles for this template -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/uoj-theme.css?v=2.33" />		
		<!-- jQuery (necessary for Bootstrap\'s JavaScript plugins) -->
		<script src="http://zhengruioi.com/js/jquery.min.js"></script>		
		<!-- jQuery autosize -->
		<script src="http://zhengruioi.com/js/jquery.autosize.min.js"></script>		<script type="text/javascript">
			$(document).ready(function() {
				$('textarea').autosize();
			});
		</script>
		
		<!-- jQuery cookie -->
		<script src="http://zhengruioi.com/js/jquery.cookie.min.js"></script>		
		<!-- jQuery modal -->
		<script src="http://zhengruioi.com/js/jquery.modal.js"></script>		
		<!-- jQuery tag canvas -->
				
		<!-- Include all compiled plugins (below), or include individual files as needed -->
		<script src="http://zhengruioi.com/js/bootstrap.min.js?v=2015.5.31"></script>		
		<!-- Color converter -->
		<script src="http://zhengruioi.com/js/color-converter.min.js"></script>		
		<!-- uoj -->
		<script src="http://zhengruioi.com/js/uoj.js?v=2016.8.15"></script>		
		<!-- LAB -->
		<script src="http://zhengruioi.com/js/LAB.min.js"></script>
		<!-- UOJ ico -->
		<link rel="shortcut icon" href="http://zhengruioi.com/pictures/UOJ.ico" />
		
				
				
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sweetalert.min.css" />		<script src="http://zhengruioi.com/js/sweetalert.min.js"></script>
				
				
				
				<!-- MathJax -->

        <script type="text/x-mathjax-config">
			MathJax.Hub.Config({
				showProcessingMessages: false,
				tex2jax: {
					inlineMath: [["$", "$"], ["\\\\(", "\\\\)"]],
					processEscapes:true
				},
				menuSettings: {
					zoom: "Hover"
    			}
			});
		</script>
<!--		<script src="//cdn.bootcss.com/mathjax/2.6.0/MathJax.js?config=TeX-AMS_HTML"></script>-->
        <script src="/js/MathJax-2.7.9/MathJax.js?config=TeX-AMS_HTML"></script>
        <!-- <script src="https://cdn.bootcdn.net/ajax/libs/mathjax/2.6.0/config/TeX-AMS_HTML-full.js"></script> -->
				
				<!-- jquery form -->
		<script src="http://zhengruioi.com/js/jquery.form.min.js"></script>				
		
				
				
				
				
				<!-- shjs -->
		<link type="text/css" rel="stylesheet" href="http://zhengruioi.com/css/sh_typical.min.css" />		<script src="http://zhengruioi.com/js/sh_main.min.js"></script>		<script type="text/javascript">$(document).ready(function(){sh_highlightDocument()})</script>
				
		
		<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
		<!--[if lt IE 9]>
			<script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
			<script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
		<![endif]-->
		
		<script type="text/javascript">
		before_window_unload_message = null;
		$(window).on('beforeunload', function() {
			if (before_window_unload_message !== null) {
			    return before_window_unload_message;
			}
		});
		</script>
		
			</head>
	<body role="document">
		<div class="container theme-showcase" role="main">
						<div>
				<ul class="nav nav-pills pull-right" role="tablist">
									<li class="dropdown">
						<a href="#" data-toggle="dropdown">
							<span class="uoj-username" data-rating="1503" data-link="0">Meko</span> 						</a>
						<ul class="dropdown-menu" role="menu">
							<li role="presentation"><a href="http://zhengruioi.com/user/msg">私信&nbsp;&nbsp;</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/profile/Meko">个人信息</a></li>
							<li role="presentation"><a href="http://zhengruioi.com/user/system-msg">系统消息&nbsp;&nbsp;</a></li>
													</ul>
					</li>
					<li role="presentation"><a href="http://zhengruioi.com/logout?_token=qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy">登出</a></li>
								</ul>
				<h1 class="hidden-xs"><a href="http://zhengruioi.com"><img src="http://zhengruioi.com/pictures/UOJ_small.png" alt="UOJ Logo" class="img-rounded" style="width:39px; height:39px;" /></a> Zhengrui Online Judge</h1>
				<h1 class="visible-xs">ZROI</h1>
			</div>
			
			<div class="navbar navbar-default" role="navigation">
	<div class="container-fluid">
		<div class="navbar-header">
			<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".navbar-collapse">
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
				<span class="icon-bar"></span>
			</button>
			<a class="navbar-brand" href="http://zhengruioi.com">ZROI</a>
		</div>
		<div class="navbar-collapse collapse">
			<ul class="nav navbar-nav">
				<li><a href="/contests">比赛</a></li>
				<li><a href="/problems">题库</a></li>
				<li><a href="/submissions">提交记录</a></li>
				<li><a href="/hacks">Hack!</a></li>
				<li><a href="/blogs">博客</a></li>
				<li><a href="/faq">帮助</a></li>
				<li><a href="/rollkings">卷王榜</a></li>
<!--                <li><a href="/rollkings">--><?//= UOJLocale::get('roll kings nav') ?><!--</a></li>-->
									<li><a data-target="#switchModal" href="#" data-toggle="modal">切换</a></li>
					<div class="modal fade in" id="switchModal" tabindex="-1" aria-labelledby="switchModalLabel" aria-hidden="true" style="display: none;">
						<div class="modal-dialog" style="width: 400px;">
							<div class="modal-content">
								<div class="modal-header" style="height: 51px;">
									<h4 class="modal-title" id="switchModalLabel" style="float:left">权限选择</h4>
									<button type="button" class="close" data-dismiss="modal" aria-label="Close" style="float:right">
									<span aria-hidden="true">×</span>
									</button>
								</div>
								<form name="switchChooseForm" method="post">
									<input type="hidden" name="switchChooseFormHiddenInput" id="switchChooseFormHiddenInput" value="switch">
									<div class="modal-body">
										<div class="table-responsive">
											<table class="table table-bordered table-hover table-striped table-text-center">
												<thead><tr>
													<th><label style="margin-bottom: 2px;">
														<input type="checkbox" style="vertical-align: middle;margin-top: 0px;" id="switchChooseAll"><span style="vertical-align: middle"> 全选</span>
													</label></th>
													<th style="vertical-align: middle">团队名称</th>
												</tr></thead>
												<tbody>
													<tr><td><input id="switchCheckbox86" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="86"></td><td>金华一中2022联赛训练</td></tr><tr><td><input id="switchCheckbox98" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="98"></td><td>22暑期CD集训</td></tr><tr><td><input id="switchCheckbox103" type="checkbox" checked="" style="width:100%" name="switchCheckbox[]" value="103"></td><td>22noip赛前20天</td></tr>													
												</tbody>
											</table>
										</div>
									</div>
									<div class="modal-footer">
										<button type="button" class="btn btn-secondary" data-dismiss="modal">取消</button>
										<button type="submit" class="btn btn-primary">确认</button>
									</div>
								</form>
								<script type="text/javascript">
									$("#switchChooseAll").click(function() {
										if (this.checked) {
											$("#switchCheckbox86").prop("checked", true);$("#switchCheckbox98").prop("checked", true);$("#switchCheckbox103").prop("checked", true);										} else {
											$("#switchCheckbox86").prop("checked", false);$("#switchCheckbox98").prop("checked", false);$("#switchCheckbox103").prop("checked", false);										}
									})
								</script>
							</div>
						</div>
					</div>
							</ul>
		</div><!--/.nav-collapse -->
	</div>
</div>
<script type="text/javascript">
function swalConfirm(text) {
	return swal({
		html : text,
		type : 'warning',
		showCancelButton : true,
		allowOutsideClick : false,
		confirmButtonText : 'Yes',
		cancelButtonText : 'No',
		focusCancel : true
	});
}

function switchTo(id) {
	swalConfirm('您确定要切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 吗？')
	.then(function() {
		$.post('/', {
			id : id,
			type : 'switch'
		}, function(msg) {
			if (msg == 'ok') {
				swal('', '成功切换到 <strong>' + $('#team-name-' + id).text() + '</strong> 啦', 'success')
				.then(function() {
					window.location.reload();
				});
			} else swal('', '切换失败，如有疑问请联系蔡老师', 'error');
		});
	});
}
</script>
						
			<div class="uoj-content">
<script src="/js/sec.min.js"></script><script>__canvasWM({content: 'qbYCXKLlZmD5j5oAWdfpCwJphDflZhw/KNsUB9eMQQ8='});</script>
<h1 class="page-header text-center" style="margin-bottom:0px;border-bottom:0px">#458. 我才不是萝莉控呢</h1>
<div class="row" style="margin-bottom:20px;border-bottom:1px">
	<div class="col-sm-2"></div>
	<div class="col-sm-8 text-center">
					<div class="btn-group" role="group" aria-label="First group">
				<button type="button" class="uoj-tag btn" disabled="">时间限制：3000 ms</button>
				<button type="button" class="uoj-tag btn" disabled="">空间限制：512 MiB</button>
				<button type="button" class="uoj-tag btn" disabled="">题目类型：传统型</button>
				<button type="button" class="uoj-tag btn" disabled="">答案检查器：文本比较</button>
			</div>
			</div>
	<div class="col-sm-2 text-right">
		<div class="uoj-click-zan-block" data-id="458" data-type="P" data-val="0" data-cnt="17"></div>	</div>
</div>
<a role="button" class="btn btn-info pull-right" href="/problem/458/statistics"><span class="glyphicon glyphicon-stats"></span> 统计</a>
	<a role="button" class="btn btn-info pull-right" href="/download.php?type=tutorial&id=458" style="margin-right: 5px"><span class="glyphicon glyphicon-file"></span> 题解</a>

<ul class="nav nav-tabs" role="tablist">
	<li class="active"><a href="#tab-statement" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-book"></span> 描述</a></li>
	<li><a href="#tab-submit-answer" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-upload"></span> 提交</a></li>
		<li><a href="#tab-custom-test" role="tab" data-toggle="tab"><span class="glyphicon glyphicon-console"></span> 自定义测试</a></li>
			<li><a href="/download.php?type=problem&id=458" role="button"><span class="glyphicon glyphicon-download"></span> 下发文件下载</a></li>
			</ul>
<div class="tab-content">
	<div class="tab-pane active" id="tab-statement">
		<!--			<iframe src="/static/vuRNP7EmK12g/3.pdf" width="100%" height="700px"></iframe>-->
			<iframe src="/download.php?type=statement&id=458" width="100%" height="700px"></iframe>
				<article class="top-buffer-md"><p>是 $\lceil\frac y 2 \rceil$ 和 $B_x$。</p>
<p>时间限制 : 3s</p>
<p>空间限制 : 512M</p>
<p><a href="http://zhengruioi.com/download.php?type=problem&amp;id=458">样例下载</a></p>
</article>
	</div>
	<div class="tab-pane" id="tab-submit-answer">
		<div class="top-buffer-sm"></div>
				<form action="/problem/458" method="post" class="form-horizontal" id="form-answer" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-answer_answer"></div>
<script type="text/javascript">
$('#form-group-answer_answer').source_code_form_group('answer_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="text-center"><button type="submit" id="button-submit-answer" name="submit-answer" value="answer" class="btn btn-default">提交</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-answer').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-answer'] = "";
			$.ajax({
				url : '/problem/458',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		return ok;
	});
});
</script>	</div>
		<div class="tab-pane" id="tab-custom-test">
		<div class="top-buffer-sm"></div>
		<form action="/problem/458" method="post" class="form-horizontal" id="form-custom_test" enctype="multipart/form-data"><input type="hidden" name="_token" id="_token" value="qbqLWylzeqqAtvl4fq96LiBsXZYB1Zt6lP0ITANh6CNP4OC07ojmMg8QmZJy" /><div class="form-group" id="form-group-custom_test_answer"></div>
<script type="text/javascript">
$('#form-group-custom_test_answer').source_code_form_group('custom_test_answer', '源文件:answer', "<option>C++<\/option><option>Python2.7<\/option><option>Java7<\/option><option>C++11<\/option><option selected=\"selected\">C++14<\/option><option>Python3<\/option><option>Java8<\/option><option>C<\/option><option>Pascal<\/option>");
</script><div class="form-group" id="form-group-custom_test_input"></div>
<script type="text/javascript">
$('#form-group-custom_test_input').text_file_form_group('custom_test_input', '文本文件:input.txt');
</script><div id="div-custom_test_result"></div><div class="text-center"><button type="submit" id="button-submit-custom_test" name="submit-custom_test" value="custom_test" class="btn btn-default">运行</button></div></form><script type="text/javascript">
$(document).ready(function() {
	$('#form-custom_test').keydown(function(e) {
		if (e.keyCode == 13 && e.ctrlKey) {
			$('#button-submit-custom_test').click();
		}
	});
	$('#form-custom_test').submit(function(e) {
		var ok = true;
		var post_data = {};
		if (post_data != {}) {
			post_data['check-custom_test'] = "";
			$.ajax({
				url : '/problem/458',
				type : 'POST',
				dataType : 'json',
				async : false,

				data : post_data,
				success : function(data) {
					if (data.extra != undefined) {
						alert(data.extra);
						ok = false;
					}
				}
			});
		}
		$(this).find("input[type='file']").each(function() {
			for (var i = 0; i < this.files.length; i++) {
				if (this.files[i].size > 10 * 1024 * 1024) {
					$('#div-' + $(this).attr('name')).addClass('has-error');
					$('#help-' + $(this).attr('name')).text('文件大小不能超过10M');
					ok = false;
				} else {
					$('#div-' + $(this).attr('name')).removeClass('has-error');
					$('#help-' + $(this).attr('name')).text('');
				}
			}
		});
		e.preventDefault();
		if (ok) {
			$(this).ajaxSubmit({
				beforeSubmit: function(formData) {
					formData.push({name: 'submit-custom_test', value: 'custom_test', type: 'submit'});
				},
				success : function(response_text) {custom_test_onsubmit(response_text, $('#div-custom_test_result')[0], '/problem/458?get=custom-test-status-details')}
			});
		}
	});
});
</script>	</div>
	</div>
			</div>
						<div class="uoj-footer">
				<p>
					<a href="http://zhengruioi.com/problem/458?locale=zh-cn"><img src="/pictures/lang/cn.png" alt="中文" /></a> 
					<a href="http://zhengruioi.com/problem/458?locale=en"><img src="/pictures/lang/gb.png" alt="English" /></a>
				</p>
				
				<ul class="list-inline">
					<li>Zhengrui Online Judge</li>
									</ul>
				
				<p>Server time: 2022-11-17 11:38:28 &nbsp; | &nbsp;  <a href="http://www.beian.miit.gov.cn/">浙ICP备17047493号</a></p>
			</div>
					</div>
		<!-- /container -->
	</body>
</html>

