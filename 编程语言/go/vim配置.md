1. [参考连接](https://github.com/astaxie/build-web-application-with-golang/blob/master/ebook/01.4.md)

配置vim高亮显示

cp -r $GOROOT/misc/vim/* ~/.vim/

						 在~/.vimrc文件中增加语法高亮显示

						 filetype plugin indent on
						 syntax on

						 安装[Gocode](https://github.com/nsf/gocode/)

						 go get -u github.com/nsf/gocode

						 gocode默认安装到$GOBIN下面。

						 配置Gocode

						 ~ cd $GOPATH/src/github.com/nsf/gocode/vim
						 ~ ./update.bash
						 ~ gocode set propose-builtins true
						 propose-builtins true
						 ~ gocode set lib-path "/home/border/gocode/pkg/linux_amd64"
						 lib-path "/home/border/gocode/pkg/linux_amd64"
						 ~ gocode set
						 propose-builtins true
						 lib-path "/home/border/gocode/pkg/linux_amd64"

						 gocode set里面的两个参数的含意说明：

						 propose-builtins：是否自动提示Go的内置函数、类型和常量，默认为false，不提示。

						 lib-path:默认情况下，gocode只会搜索$GOPATH/pkg/$GOOS_$GOARCH 和 $GOROOT/pkg/$GOOS_$GOARCH目录下的包，当然这个设置就是可以设置我们额外的lib能访问的路径

						 恭喜你，安装完成，你现在可以使用:e main.go体验一下开发Go的乐趣。

更多VIM 設定, 可參考[連結](http://monnand.me/p/vim-golang-environment/zhCN/)

