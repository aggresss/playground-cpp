function Printmsg()
    --故意制造调用出错
    printaa("hello world")
end

function Errorhandle(str)
    return string.upper(str)
end
