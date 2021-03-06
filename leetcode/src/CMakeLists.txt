cmake_minimum_required(VERSION 3.13)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        add_binary.cpp
        add_binary.h
        add_two_numbers.cpp
        add_two_numbers.h
        balanced_binary_tree.cpp
        balanced_binary_tree.h
        binary_tree_inorder_traversal.cpp
        binary_tree_inorder_traversal.h
        binary_tree_level_order_traversal.cpp
        binary_tree_level_order_traversal.h
        binary_tree_level_order_traversal_2.cpp
        binary_tree_level_order_traversal_2.h
        binary_tree_zigzag_level_order_traversal.cpp
        binary_tree_zigzag_level_order_traversal.h
        can_jump.cpp
        can_jump.h
        climbStairs.cpp
        climbStairs.h
        combination_sum.cpp
        combination_sum.h
        combination_sum2.cpp
        combination_sum2.h
        combine.cpp
        combine.h
        construct_binary_tree_from_inorder_and_postorder_traversal.cpp
        construct_binary_tree_from_inorder_and_postorder_traversal.h
        construct_binary_tree_from_preorder_and_inorder_traversal.cpp
        construct_binary_tree_from_preorder_and_inorder_traversal.h
        convert_sorted_array_to_binary_search_tree.cpp
        convert_sorted_array_to_binary_search_tree.h
        convert_sorted_list_to_binary_search_tree.cpp
        convert_sorted_list_to_binary_search_tree.h
        data_structures.cpp
        data_structures.h
        decode_ways.cpp
        decode_ways.h
        divide.cpp
        divide.h
        exist.cpp
        exist.h
        find_median_sorted_arrays.cpp
        find_median_sorted_arrays.h
        find_substring.cpp
        find_substring.h
        first_missing_positive.cpp
        first_missing_positive.h
        four_sum.cpp
        four_sum.h
        full_justify.cpp
        full_justify.h
        generate_matrix.cpp
        generate_matrix.h
        generate_parenthesis.cpp
        generate_parenthesis.h
        get_permutation.cpp
        get_permutation.h
        gray_code.cpp
        gray_code.h
        group_anagrams.cpp
        group_anagrams.h
        heads.h
        insert.cpp
        insert.h
        int_to_roman.cpp
        int_to_roman.h
        interleaving_string.cpp
        interleaving_string.h
        is_match_2.cpp
        is_match_2.h
        is_number.cpp
        is_number.h
        is_valid.cpp
        is_valid.h
        is_valid_sudoku.cpp
        is_valid_sudoku.h
        isMatch.cpp
        isMatch.h
        isPalindrome.cpp
        isPalindrome.h
        jump.cpp
        jump.h
        largest_rectangle_in_histogram.cpp
        largest_rectangle_in_histogram.h
        leetcode.cpp
        length_of_last_word.cpp
        length_of_last_word.h
        length_of_longest_substring.cpp
        length_of_longest_substring.h
        letter_combinations.cpp
        letter_combinations.h
        longest_common_prefix.cpp
        longest_common_prefix.h
        longest_palindrome.cpp
        longest_palindrome.h
        longest_valid_parentheses.cpp
        longest_valid_parentheses.h
        max_area.cpp
        max_area.h
        max_subarray.cpp
        max_subarray.h
        maximalRectangle.cpp
        maximalRectangle.h
        maximum_depth_of_binary_tree.cpp
        maximum_depth_of_binary_tree.h
        merge.cpp
        merge.h
        merge_k_lists.cpp
        merge_k_lists.h
        merge_sorted_array.cpp
        merge_sorted_array.h
        merge_two_lists.cpp
        merge_two_lists.h
        min_distance.cpp
        min_distance.h
        min_path_sum.cpp
        min_path_sum.h
        min_window.cpp
        min_window.h
        minimum_depth_of_binary_tree.cpp
        minimum_depth_of_binary_tree.h
        mutiply.cpp
        mutiply.h
        my_atoi.cpp
        my_atoi.h
        my_pow.cpp
        my_pow.h
        mysqrt.cpp
        mysqrt.h
        next_permutation.cpp
        next_permutation.h
        partition_list.h
        path_sum.cpp
        path_sum.h
        permute.cpp
        permute.h
        permute_unique.cpp
        permute_unique.h
        plus_one.cpp
        plus_one.h
        recover_binary_search_tree.cpp
        recover_binary_search_tree.h
        remove_duplicates.cpp
        remove_duplicates.h
        remove_duplicates2.cpp
        remove_duplicates2.h
        remove_duplicates_from_sorted_list.cpp
        remove_duplicates_from_sorted_list.h
        remove_duplicates_from_sorted_list2.cpp
        remove_duplicates_from_sorted_list2.h
        remove_element.cpp
        remove_element.h
        remove_nth_from_end.cpp
        remove_nth_from_end.h
        restore_ip_addresses.cpp
        restore_ip_addresses.h
        reverse.cpp
        reverse.h
        reverse_k_group.cpp
        reverse_k_group.h
        reverse_linked_list_2.cpp
        reverse_linked_list_2.h
        roman_to_int.cpp
        roman_to_int.h
        rotate.cpp
        rotate.h
        rotate_right.cpp
        rotate_right.h
        same_tree.cpp
        same_tree.h
        scramble_string.cpp
        scramble_string.h
        search.cpp
        search.h
        search2.cpp
        search2.h
        search_insert.cpp
        search_insert.h
        search_matrix.cpp
        search_matrix.h
        search_range.cpp
        search_range.h
        set_zeros.cpp
        set_zeros.h
        simplify_path.cpp
        simplify_path.h
        solve_n_queens.cpp
        solve_n_queens.h
        solve_sudoku.cpp
        solve_sudoku.h
        sort_colors.cpp
        sort_colors.h
        spiral_order.cpp
        spiral_order.h
        str_str.h
        subsets.cpp
        subsets.h
        subsets_2.cpp
        subsets_2.h
        swap_pairs.cpp
        swap_pairs.h
        symmetric_tree.cpp
        symmetric_tree.h
        three_sum.cpp
        three_sum.h
        three_sum_closest.cpp
        three_sum_closest.h
        trap.cpp
        trap.h
        two_sum.cpp
        two_sum.h
        unique_binary_search_trees.cpp
        unique_binary_search_trees.h
        unique_binary_search_trees_2.cpp
        unique_binary_search_trees_2.h
        unique_paths.cpp
        unique_paths.h
        unique_paths_with_obstacles.cpp
        unique_paths_with_obstacles.h
        utils.cpp
        utils.h
        validate_binary_search_tree.cpp
        validate_binary_search_tree.h
        zigzag_convert.cpp
        zigzag_convert.h flatten_binary_tree_to_linked_list.cpp flatten_binary_tree_to_linked_list.h backspace_string_compare.cpp backspace_string_compare.h coin_change_2.cpp coin_change_2.h unique_email_addresses.cpp unique_email_addresses.h find_all_numbers_disappeared_in_an_array.cpp find_all_numbers_disappeared_in_an_array.h find_the_duplicate_number.cpp find_the_duplicate_number.h flip_binary_tree_to_match_preorder_traversal.cpp flip_binary_tree_to_match_preorder_traversal.h path_sum_3.cpp path_sum_3.h minimum_number_of_refueling_stops.cpp minimum_number_of_refueling_stops.h power_of_two.cpp power_of_two.h string_without_AAA_or_BBB.cpp string_without_AAA_or_BBB.h)
