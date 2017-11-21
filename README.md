## SETUP

Use [CocoaPods](https://github.com/CocoaPods/CocoaPods), [Carthage](https://github.com/carthage/carthage) or [Set up manually](#setting-up-manually)

### CocoaPods

1. Add Innometrics to your project's `Podfile`:

	```ruby
	platform :ios, '9.0'
	use_frameworks!

	target :MyApp do
	  # your app dependencies
	  pod 'Innometrics', :git => 'https://github.com/Innometrics/iOS-SDK.git', :tag => '2.0.0'
	end
	```

2. Run `pod update` or `pod install` in your project directory.

### Carthage

1. Add Innometrics to your project's `Cartfile`

    ```
    github "Innometrics/iOS-SDK" ~> 2.0
    ```

1. Run `carthage update` in your project directory
1. Drag `Innometrics.framework` and `PixateFreestyle.framework` (located in Carthage/Build/iOS/) into your application’s Xcode project, and add it to your test target(s).
1. Add "Copy files" phase to Build Phases, select Frameworks and add both Innometrics and PixateFreestyle.
1. A new `Run Script Phase` must be added to copy the framework. The instructions can be found on [Carthage's getting started instructions](https://github.com/carthage/carthage#getting-started)

### Setting up manually

1. Download `Innometrics.framework`, `PixateFreestyle.framework`, `CoreParse.framework` and `SocketRocket.framework`
1. Drag frameworks into your application’s Xcode project, and add it to your test target(s).
1. Drag frameworks to "Embedded binaries" on General tab of your target.

### Preparing to run on device and publish app with the SDK
1. You may need to disable BitCode: in Target Preferences pane's Build Settings tab set Enable Bitcode to No



