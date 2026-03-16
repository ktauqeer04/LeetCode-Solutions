func containsDuplicate(nums []int) bool {
    m := make(map[int]int)
    for i := 0; i < len(nums); i++ {
        m[nums[i]] += 1
    }

    for _, value := range m {
        if value >= 2 {
            return true
        }
    }

    return false

}