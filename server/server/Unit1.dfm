object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 305
  ClientWidth = 512
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 40
    Top = 152
    Width = 177
    Height = 65
    Caption = 'STOP'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 40
    Top = 8
    Width = 177
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    Text = '127.0.0.1'
  end
  object Edit2: TEdit
    Left = 40
    Top = 45
    Width = 65
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    MaxLength = 4
    ParentFont = False
    TabOrder = 2
    Text = '777'
  end
  object Memo1: TMemo
    Left = 240
    Top = 32
    Width = 241
    Height = 185
    Lines.Strings = (
      '')
    TabOrder = 3
  end
  object Button2: TButton
    Left = 40
    Top = 81
    Width = 177
    Height = 65
    Caption = 'START'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = Button2Click
  end
  object Panel1: TPanel
    Left = 0
    Top = 223
    Width = 512
    Height = 82
    Align = alBottom
    Caption = 'Panel1'
    TabOrder = 5
    object Button3: TButton
      Left = 40
      Top = 0
      Width = 177
      Height = 73
      Caption = 'Send MSG'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = Button3Click
    end
    object Edit3: TEdit
      Left = 240
      Top = 24
      Width = 241
      Height = 27
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      TextHint = 'Enter text'
    end
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 0
    ServerType = stNonBlocking
    OnClientWrite = ServerSocket1ClientWrite
    Left = 240
    Top = 8
  end
end
