idf_component_register(
    SRCS
        "main.c"
        "../targets/basic01_linear/unprotected.c"
        "../targets/basic01_linear/protected.c"

        "../targets/basic02_single_branch/unprotected.c"
        "../targets/basic02_single_branch/protected.c"

        "../targets/basic03_branch_merge/unprotected.c"
        "../targets/basic03_branch_merge/protected.c"

        "../targets/advanced01_early_exit/unprotected.c"
        "../targets/advanced01_early_exit/protected.c"

        "../targets/advanced02_nested_decisions/unprotected.c"
        "../targets/advanced02_nested_decisions/protected.c"

        "../targets/anti_rollback/unprotected.c"
        "../targets/secure_boot/unprotected.c"
        "../targets/state_transition/unprotected.c"
        "../targets/dummy/unprotected.c"

        "../fault_injection/trigger.c"

    INCLUDE_DIRS
        "."
        "../targets/basic01_linear"
        "../targets/basic02_single_branch"
        "../targets/basic03_branch_merge"

        "../targets/advanced01_early_exit"
        "../targets/advanced02_nested_decisions"
        
        "../targets/anti_rollback"
        "../targets/secure_boot"
        "../targets/state_transition"
        "../targets/dummy"
        "../fault_injection"
)