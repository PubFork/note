##SQL包,操作数据库的SQL函数
SQL包是一个抽象包，它不管底层是用mysql还是sqlserver什么的，只是规定了操作的函数。所以需要对数据库操作还要在下载一个驱动的包

对Mysql操作需要下一个Mysql的驱动包

Url: (项目地址:https://github.com/go-sql-driver/mysql/)

Sql包里有几个定义好的类型(只列出我使用过的)：
* DB
* Row
* Rows
* Stmt
* Tx

###DB 类型有如下功能函数:
- func Open(driverName, dataSourceName string) (*DB, error) 创建一个数据库连接
- func (db *DB) Begin() (*Tx, error)	创建一个事物
- func (db *DB) Close() error 关闭数据库连接
- func (db *DB) Exec(query string, args ...interface{}) (Result, error) 执行一个没有查询结果的SQL，例如 insert，update，delete。可以使用Result类型中的方法获取一些值，例如获取插入表的id主键值
- func (db *DB) Ping() error	检查数据库是否可以连接
- func (db *DB) Prepare(query string) (*Stmt, error)	用来预先写好一个SQL，然后给出参数就可以执行了，不用每次都执行整段的SQL。
`
db.Prepare("update test set name=?,age=? where age=?");
	if result,err := stmt.Exec("周七",40,25);err==nil {
		if c,err := result.RowsAffected();err==nil {
			 fmt.Println("update count : ",c);
		}
	}
`
- func (db *DB) Query(query string, args ...interface{}) (*Rows, error) 执行一个SQL语句，并返回多行数据。使用Rows类型的方法获取结果
- func (db *DB) QueryRow(query string, args ...interface{}) *Row 执行SQL语句，返回一行数据

###Row 类型有如下功能函数：
- func (r *Row) Scan(dest ...interface{}) error 用来获取查询结果
`
var id,name string
err := db.QueryRow("Select id,name From test where id=?",1).Scan(&id,&name)
switch {
	case err == sql.ErrNoRows:
		log.Printf("No user with that ID.")
	case err != nil:
		log.Fatal(err)
	default:
		fmt.Printf("Username is %s\n", username)
}
`

###Rows 类型有如下功能函数：
- func (*Rows) Close 关闭rows，调用该函数后则无法在使用Next()获取后面的数据。默认Next()函数会在获取完所有数据后自动关闭，有时候需要在某个特殊条件触发后不在获取后续数据，这时候就可以调用该函数
- func (rs *Rows) Columns() ([]string, error)  用来回去列名
`
比如有个sql要查询id和name列的数据，调用该函数后就会返回一个字符串的数组，里面包含了sql中的需要查询的列名
`
- func (rs *Rows) Next() bool	获取后续数据，每调用一次这结果自动向后移动，知道没有数据可读返回false
- func (rs *Rows) Scan(dest ...interface{}) error 用来获取数据值，配合Next函数使用

##Stmt 类型有如下功能函数
- func (s *Stmt) Close() error 关闭这个声明
- func (s *Stmt) Exec(args ...interface{}) (Result, error) 执行预处理的SQL语句，传入替换在Prepare中?设置的值.作用和db的Exec函数一样
- func (s *Stmt) Query(args ...interface{}) (*Rows, error) 执行预处理的SQL语句，传入替换在Prepare中?设置的值.作用和db的Query函数一样
- func (s *Stmt) QueryRow(args ...interface{}) *Row 执行预处理的SQL语句，传入替换在Prepare中?设置的值.作用和db的QueryRow函数一样

## Tx 类型有如下功能函数：
- func (tx *Tx) Commit() error 提交一个事物
- func (tx *Tx) Exec(query string, args ...interface{}) (Result, error)
- func (tx *Tx) Prepare(query string) (*Stmt, error)
- func (tx *Tx) Query(query string, args ...interface{}) (*Rows, error) 
- func (tx *Tx) QueryRow(query string, args ...interface{}) *Row
- func (tx *Tx) Rollback() error 回滚事物
- func (tx *Tx) Stmt(stmt *Stmt) *Stmt
