##让nginx支持PATHINFO
nginx默认是不支持pathinfo的
`
server    
{    
	listen       80;    
	server_name  www.xxx.com;    
	index index.html index.htm index.php index.shtml;    
	root /data2/www/www.xxx.com;    

	location / {    
		if (!-e $request_filename){    
			rewrite ^(.*)$ /index.php?s=/$1 last; #rewrite模式    
			rewrite ^(.*)$ /index.php/$1 last; #pathinfo模式 任选其一    
		}    
	}    

	location ~ \.php {    
		fastcgi_pass    127.0.0.1:9000;    
		fastcgi_split_path_info ^(.+\.php)(.*)$;    
		fastcgi_param PATH_INFO $fastcgi_path_info;    
		fastcgi_param PATH_TRANSLATED $document_root$fastcgi_path_info;    
		fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;    
		include         fastcgi_params;    
		fastcgi_connect_timeout 300;    
		fastcgi_send_timeout 300;    
		fastcgi_read_timeout 300;    
	}    
}
``
