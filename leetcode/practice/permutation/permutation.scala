object Solution {
    
    def getPerm(nums: Array[Int], i: Int): List[List[Int]] = {
        var j = i
        var l: List[List[Int]] = List.empty
        if (i == nums.size) return List(nums.toList)
        for ( j <- i until nums.size ) {
            var t1 = nums(i)
            nums(i) = nums(j)
            nums(j) = t1
            l = l ++ getPerm(nums, i + 1)
            var t2 = nums(i)
            nums(i) = nums(j)
            nums(j) = t2
        }
        l
    }
    
    def permute(nums: Array[Int]): List[List[Int]] = {
        getPerm(nums, 0)
    }
}
