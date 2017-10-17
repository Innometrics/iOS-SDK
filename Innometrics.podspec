Pod::Spec.new do |s|
  s.name          = "Innometrics"
  s.version       = "2.0.0"
  s.platform      = :ios, "9.0"
  s.summary       = "Innometrics Profile Cloud client library for iOS"
  s.author        = { "Innometrics" => "dev-support@innometrics.com" }
  s.homepage      = "https://github.com/Innometrics/iOS-SDK.git"
  s.license       = { :file => 'LICENSE', :type => 'Commercial' }
  s.frameworks    = 'CoreLocation', 'Security', 'MobileCoreServices', 'SystemConfiguration', 'CoreTelephony', 'PixateFreestyle', 'CoreParse', 'SocketRocket'
  s.libraries     = 'xml2', 'sqlite3'
  s.source = {
    :git => 'https://github.com/Innometrics/iOS-SDK.git',
    :tag => 'v2.0.0'
  }
  s.ios.vendored_frameworks = 'Innometrics.framework', 'PixateFreestyle.framework', 'CoreParse.framework', 'SocketRocket.framework'
end
