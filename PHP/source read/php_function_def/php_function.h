./main/php.h:#define PHP_FUNCTION
#define PHP_FUNCTION ZEND_FUNCTION
	
./Zend/zend_API.h:#define ZEND_FUNCTION(name) ZEND_NAMED_FUNCTION(ZEND_FN(name))
#define ZEND_FUNCTION(name) ZEND_NAMED_FUNCTION(ZEND_FN(name))
#define ZEND_FN(name) zif_##name
#define ZEND_NAMED_FUNCTION(name) void name(INTERNAL_FUNCTION_PARAMETERS)

./Zend/zend.h:#define INTERNAL_FUNCTION_PARAMETERS zend_execute_data *execute_data, zval *return_value
#define INTERNAL_FUNCTION_PARAMETERS zend_execute_data *execute_data, zval *return_value

eg:
1.PHP_FUNCTION(array_fill)
2.ZEND_FUNCTION(array_fill)
3.ZEND_FN(name) zif_array_fill
4.ZEND_NAMED_FUNCTION(zif_array_fill)
5.void zif_array_fill(zend_execute_data *execute_data, zval *return_value)
