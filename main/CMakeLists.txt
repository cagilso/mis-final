idf_component_register(
    SRCS
        "main.c"
        "../targets/anti_rollback/unprotected.c"
        "../targets/secure_boot/unprotected.c"
        "../targets/state_transition/unprotected.c"
        "../targets/dummy/unprotected.c"
        "../fault_injection/trigger.c"

    INCLUDE_DIRS
        "."
        "../targets/anti_rollback"
        "../targets/secure_boot"
        "../targets/state_transition"
        "../targets/dummy"
        "../fault_injection"
)