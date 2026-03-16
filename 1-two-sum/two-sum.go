func twoSum(nums []int, target int) []int {

    m := make(map [int]int)

    for i := 0; i < len(nums); i++ {
        key := target - nums[i]
        if _, exists := m[key]; exists {
            return []int {m[key], i}
        }
        m[nums[i]] = i 
    }

    return []int {-1,-1}

}