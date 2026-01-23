@echo off
set HewView_Path=".\Hexview\hexview.exe"
set Input_hex=".\DefaultBuild\EMB YC_2.0_RL.hex"
set Output_hex=".\DefaultBuild\EMB YC_2.0_RL_flash.hex" 
if exist %HewView_Path% (
		if exist %Input_hex% (
				echo 填充中
					%HewView_Path%  /s %Input_hex% /FP:0xFF /FR:0x00020000-0x00070000  /xi:32 -o %Output_hex% 
					echo 填充完成
				) else (echo hex处理出错，本路径下不存在需要处理的%Input_hex%文件
				pause)
)else (echo hex处理出错，%HewView_Path%不存在
pause
)
