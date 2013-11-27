<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="11008008">
	<Item Name="我的电脑" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">我的电脑/VI服务器</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">我的电脑/VI服务器</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="API" Type="Folder">
			<Item Name="API ColorSensor.lvlib" Type="Library" URL="../API/API ColorSensor.lvlib"/>
			<Item Name="API DYM.lvlib" Type="Library" URL="../API/API DYM.lvlib"/>
			<Item Name="API READBC.lvlib" Type="Library" URL="../API/API READBC.lvlib"/>
			<Item Name="BarCodeAPI.dll" Type="Document" URL="../API/BarCodeAPI.dll"/>
			<Item Name="ColorSensor.dll" Type="Document" URL="../API/ColorSensor.dll"/>
			<Item Name="DyMechnicalPlatform.dll" Type="Document" URL="../API/DyMechnicalPlatform.dll"/>
		</Item>
		<Item Name="BlueControl85" Type="Folder">
			<Item Name="Button.ctl" Type="VI" URL="../BlueControl85.llb/Button.ctl"/>
			<Item Name="Combo Box.ctl" Type="VI" URL="../BlueControl85.llb/Combo Box.ctl"/>
			<Item Name="Dial.ctl" Type="VI" URL="../BlueControl85.llb/Dial.ctl"/>
			<Item Name="Enum.ctl" Type="VI" URL="../BlueControl85.llb/Enum.ctl"/>
			<Item Name="Gauge.ctl" Type="VI" URL="../BlueControl85.llb/Gauge.ctl"/>
			<Item Name="Horizontal Fill Slide.ctl" Type="VI" URL="../BlueControl85.llb/Horizontal Fill Slide.ctl"/>
			<Item Name="Horizontal Point Slide.ctl" Type="VI" URL="../BlueControl85.llb/Horizontal Point Slide.ctl"/>
			<Item Name="Knob.ctl" Type="VI" URL="../BlueControl85.llb/Knob.ctl"/>
			<Item Name="LED.ctl" Type="VI" URL="../BlueControl85.llb/LED.ctl"/>
			<Item Name="Numeric.ctl" Type="VI" URL="../BlueControl85.llb/Numeric.ctl"/>
			<Item Name="Path.ctl" Type="VI" URL="../BlueControl85.llb/Path.ctl"/>
			<Item Name="Ring.ctl" Type="VI" URL="../BlueControl85.llb/Ring.ctl"/>
			<Item Name="Square Button.ctl" Type="VI" URL="../BlueControl85.llb/Square Button.ctl"/>
			<Item Name="String.ctl" Type="VI" URL="../BlueControl85.llb/String.ctl"/>
			<Item Name="Vertical Fill Slide.ctl" Type="VI" URL="../BlueControl85.llb/Vertical Fill Slide.ctl"/>
			<Item Name="Vertical Point Slide.ctl" Type="VI" URL="../BlueControl85.llb/Vertical Point Slide.ctl"/>
			<Item Name="Waveform Chart.ctl" Type="VI" URL="../BlueControl85.llb/Waveform Chart.ctl"/>
			<Item Name="Waveform Graph.ctl" Type="VI" URL="../BlueControl85.llb/Waveform Graph.ctl"/>
		</Item>
		<Item Name="mainui.vi" Type="VI" URL="../mainui.vi"/>
		<Item Name="依赖关系" Type="Dependencies"/>
		<Item Name="程序生成规范" Type="Build"/>
	</Item>
</Project>
