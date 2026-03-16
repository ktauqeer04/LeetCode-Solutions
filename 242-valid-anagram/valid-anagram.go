func isAnagram(s string, t string) bool {

    if len(s) != len(t) {
        return false
    }

    m := make([]int, 26)
    n := make([]int, 26)

    for i := 0; i < len(s); i++ {
        m[s[i] - 'a']++
        n[t[i] - 'a']++
    }

    // for _, str := range s {
    //     m[str]++
    // }

    for i := 0; i < len(m); i++ {
        if m[i] != n[i] {
            return false
        }
    }

    return true

}