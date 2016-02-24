## SETUP

Use [CocoaPods](https://github.com/CocoaPods/CocoaPods), [Carthage](https://github.com/carthage/carthage) or [Set up manually](#setting-up-manually)

### CocoaPods

1. Add Innometrics to your project's `Podfile`:

	```ruby
	target :MyApp do
	  # your app dependencies
	  pod 'Innometrics', :git => 'https://github.com/Innometrics/iOS-SDK.git', :tag => 'v0.3'
	end
	```

2. Run `pod update` or `pod install` in your project directory.

### Carthage

1. Add Innometrics to your project's `Cartfile`

    ```
    github "Innometrics/iOS-SDK" ~> 0.3
    ```

1. Run `carthage update` in your project directory
1. Drag `Innometrics.framework` and `PixateFreestyle.framework` (located in Carthage/Build/iOS/) into your application’s Xcode project, and add it to your test target(s).
1. Add "Copy files" phase to Build Phases, select Frameworks and add both Innometrics and PixateFreestyle.
1. A new `Run Script Phase` must be added to copy the framework. The instructions can be found on [Carthage's getting started instructions](https://github.com/carthage/carthage#getting-started)

### Setting up manually

1. Download `Innometrics.framework` and `PixateFreestyle.framework`
1. Drag `Innometrics.framework` and `PixateFreestyle.framework` (located in Carthage/Build/iOS/) into your application’s Xcode project, and add it to your test target(s).
1. Add "Copy files" phase to Build Phases, select Frameworks and add both Innometrics and PixateFreestyle.
1. Remove invalid architectures from universal binary frameworks before submit App to iTunes Connect. More information you can find [here](http://stackoverflow.com/questions/29634466/how-to-export-fat-cocoa-touch-framework-for-simulator-and-device#answer-31270427). You can use [strip-frameworks.sh](https://github.com/realm/realm-cocoa/blob/f07d1af226b67c0aefb150d12da3fd34c5d64087/scripts/strip-frameworks.sh) to workaround this issue.

### Preparing to run on device and publish app with the SDK
1. You may need to disable BitCode: in Target Preferences pane's Build Settings tab set Enable Bitcode to No



