function(copy_locales target)
	set(dir "$<TARGET_FILE_DIR:${target}>")
	add_custom_command(TARGET "${target}" POST_BUILD
						COMMAND "${CMAKE_COMMAND}" -E copy_directory
						"${CMAKE_SOURCE_DIR}/locales" "${dir}/locales")
endfunction()