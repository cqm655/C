object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 330
  ClientWidth = 547
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 272
    Top = 8
    Width = 267
    Height = 209
    TabOrder = 0
  end
  object Button1: TButton
    Left = 48
    Top = 86
    Width = 161
    Height = 51
    Caption = 'Connect to Server'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 48
    Top = 8
    Width = 147
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    Text = '127.0.0.1'
  end
  object Edit2: TEdit
    Left = 48
    Top = 47
    Width = 65
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    Text = '777'
  end
  object Button2: TButton
    Left = 48
    Top = 143
    Width = 201
    Height = 74
    Caption = 'Diconnect from Server'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button2Click
  end
  object Panel1: TPanel
    Left = 0
    Top = 226
    Width = 547
    Height = 104
    Align = alBottom
    TabOrder = 5
    object Button3: TButton
      Left = 48
      Top = 16
      Width = 201
      Height = 73
      Caption = 'Send MSG'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
    object Edit3: TEdit
      Left = 272
      Top = 16
      Width = 267
      Height = 21
      TabOrder = 1
    end
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnRead = ClientSocket1Read
    Left = 224
    Top = 32
  end
end