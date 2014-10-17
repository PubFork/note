获取字符的编码库`chardet`
-

安装 pip install chardet

获取字符编码

	# coding: UTF-8
	import requests
	import chardet

	req = requests.get("http://www.baidu.com/")                                                                                                                                                                                                                                   
	print chardet.detect(req.content)
	结果{'confidence': 0.99, 'encoding': 'utf-8'}
	encoding表示编码，confidence表示准确度
	
