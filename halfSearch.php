/**
	 * PHP实现二分查找
	 * @param array $arr 接收一维数组参数
	 * @param int $m 数组大小
	 * @param $goal 目标值
	 * @param $b 数组起始值
	 */
	public function halfSearch($arr,$b,$m,$goal){

		if($goal > $arr[($b + $m)/2]){
			echo "><br />";
			self::halfSearch($arr,($b + $m)/2,$m,$goal);
		}else if($goal < $arr[($b + $m)/2]){
			echo "<<br />";
			self::halfSearch($arr,$b,($m + $b)/2,$goal);
		}else{
			echo $goal;
			return $goal;
		}
	}

	/**
	 * 将数组冒泡排序
	 * @param $arr
	 * @return mixed
	 */
	public function desc($arr){
		for($i = 0;$i < count($arr) - 1;$i++){
			for($j = $i + 1;$j < count($arr);$j++){
				if($arr[$i] > $arr[$j]){
					$temp = $arr[$i];
					$arr[$i] = $arr[$j];
					$arr[$j] = $temp;
				}
			}
		}
		return $arr;
	}
	/**
	 * 二分查找
	 */
	public function half($goal){
		$arr = array(1,56,4,5,7,9,12,22,49,88,73,29,35,18,105,221,335,559,441,241,531,965,833,354);
		if(!in_array($goal,$arr)){
			echo "不存在目标数值!";
			exit;
		}
		self::halfSearch(self::desc($arr),0,count($arr),$goal);
	}
