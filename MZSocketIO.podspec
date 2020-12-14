Pod::Spec.new do |s|
  s.authors      = "Mengzhu"
  s.name         = "MZSocketIO"
  s.version      = "0.0.3"
  s.summary      = "MZSocketIO iOS SDK"
  s.description  = "Provide MZSocketIO Server Function"
  s.homepage     = "http://www.zmengzhu.com"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "sunxianhao" => "sunxianhao@rd.zmengzhu.com" }
  s.source       = { :git => "https://github.com/mengzhuSDK/MZSocketIO-iOS.git", :tag => "#{s.version}" }
  s.requires_arc = true  
  s.ios.deployment_target = '8.0'
  s.frameworks = 'Foundation', 'JavaScriptCore', 'WebKit'
  s.source_files = 'MZSocketIO/*'
  # s.public_header_files = 'MZSocketIO/*.h'
  end