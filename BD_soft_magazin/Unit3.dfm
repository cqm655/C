object dm: Tdm
  OldCreateOrder = False
  Height = 372
  Width = 621
  object FDConnection1: TFDConnection
    Params.Strings = (
      'Database=magazin'
      'Server=PC-LITE'
      'OSAuthent=Yes'
      'DriverID=MSSQL')
    Connected = True
    LoginPrompt = False
    Left = 8
    Top = 8
  end
  object QUM: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT * FROM UNIT_MASURA')
    Left = 64
    Top = 8
  end
  object DSQUM: TDataSource
    DataSet = QUM
    Left = 104
    Top = 8
  end
  object qprodus: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT * FROM PRODUSE')
    Left = 24
    Top = 72
  end
  object dsqprodus: TDataSource
    DataSet = qprodus
    Left = 72
    Top = 72
  end
  object FDStoredProc1: TFDStoredProc
    Connection = FDConnection1
    StoredProcName = 'MAGAZIN.dbo.FACTURA'
    Left = 32
    Top = 144
    ParamData = <
      item
        Position = 1
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        ParamType = ptInput
      end
      item
        Position = 2
        Name = '@D'
        DataType = ftDate
        ParamType = ptInput
      end
      item
        Position = 3
        Name = '@N'
        DataType = ftString
        ParamType = ptInput
        Size = 20
      end
      item
        Name = '@E'
        DataType = ftString
      end>
  end
  object qliber: TFDQuery
    Connection = FDConnection1
    Left = 16
    Top = 200
  end
  object qedit: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'UPDATE PRODUSE SET'
      'DENUMIRE=:DENUMIRE,'
      'COD_PRODUS=:COD_PRODUS'
      ''
      'WHERE PRODUSE_ID=:PRODUSE_ID')
    Left = 24
    Top = 256
    ParamData = <
      item
        Name = 'DENUMIRE'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'COD_PRODUS'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'PRODUSE_ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object qreceptie: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      
        'select FR.*,R.*,O.NUME+'#39' '#39'+O.PRENUME AS OPERATOR, P.DENUMIRE AS ' +
        'PRODUS, P.COD_PRODUS, UM.ABREVIERE'
      
        'FROM RECEPTIE R INNER JOIN FACTURA_REC FR ON FR.FACTURA_REC_ID=R' +
        '.FACTURA_REC_ID'
      
        '                INNER JOIN UNIT_MASURA UM ON UM.UNIT_MASURA_ID=R' +
        '.UNIT_MASURA_ID'
      #9#9#9#9'INNER JOIN OPERATOR O ON O.OPERATOR_ID=R.OPERATOR_ID'
      #9#9#9#9'INNER JOIN PRODUSE P ON P.PRODUSE_ID=R.PRODUSE_ID'
      'WHERE FR.FACTURA_REC_ID=:FACTURA_REC_ID')
    Left = 32
    Top = 312
    ParamData = <
      item
        Name = 'FACTURA_REC_ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object dsqreceptie: TDataSource
    DataSet = qreceptie
    Left = 80
    Top = 320
  end
  object qvanzare: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      
        'select FR.*,R.*,V.*,C.*,CL.NUME+'#39' '#39'+CL.PRENUME AS CLIENT, O.NUME' +
        '+'#39' '#39'+O.PRENUME AS OPERATOR, '
      
        '      P.DENUMIRE AS PRODUS, P.COD_PRODUS as cod, UM.ABREVIERE, D' +
        '.NUME AS DISCOUNT, D.VALOAREA,'
      '      v.vanzare_id as idd'
      ''
      
        'FROM RECEPTIE R INNER JOIN FACTURA_REC FR ON FR.FACTURA_REC_ID=R' +
        '.FACTURA_REC_ID'
      
        '                INNER JOIN UNIT_MASURA UM ON UM.UNIT_MASURA_ID=R' +
        '.UNIT_MASURA_ID'
      #9#9#9#9'INNER JOIN OPERATOR O ON O.OPERATOR_ID=R.OPERATOR_ID'
      #9#9#9#9'INNER JOIN PRODUSE P ON P.PRODUSE_ID=R.PRODUSE_ID'
      #9#9#9#9'INNER JOIN VANZARE V ON R.RECEPTIE_ID=V.RECEPETIE_ID'
      #9#9#9#9'INNER JOIN CEC C ON C.CEC_ID=V.CEC_ID'
      #9#9#9#9'INNER JOIN CLIENT CL ON CL.CLIENT_ID=C.CLIENT_ID'
      #9#9#9#9'INNER JOIN DISCOUNT D ON D.DISCOUNT_ID=CL.DISCOUNT_ID'
      '                 where c.CEC_ID=:CEC_ID')
    Left = 464
    Top = 32
    ParamData = <
      item
        Name = 'CEC_ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object dsqvanzare: TDataSource
    DataSet = qvanzare
    Left = 408
    Top = 32
  end
  object proccec: TFDStoredProc
    Connection = FDConnection1
    StoredProcName = 'MAGAZIN.dbo.CECC'
    Left = 472
    Top = 88
    ParamData = <
      item
        Position = 1
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        ParamType = ptResult
      end
      item
        Position = 2
        Name = '@OPER'
        DataType = ftInteger
        ParamType = ptInput
      end
      item
        Position = 3
        Name = '@CLIENT'
        DataType = ftInteger
        ParamType = ptInput
      end
      item
        Position = 4
        Name = '@FIRMA'
        DataType = ftInteger
        ParamType = ptInput
      end>
  end
  object qliber2: TFDQuery
    Connection = FDConnection1
    Left = 56
    Top = 200
  end
  object qcec: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      
        'select * from CEC where OPERATOR_ID=:OPERATOR_ID and cast(DATA_C' +
        'EC as date) between :D1 and :D2'
      'and nr_cec>0')
    Left = 440
    Top = 216
    ParamData = <
      item
        Name = 'OPERATOR_ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'D1'
        DataType = ftDate
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'D2'
        DataType = ftDate
        ParamType = ptInput
        Value = Null
      end>
  end
  object dsqcec: TDataSource
    DataSet = qcec
    Left = 384
    Top = 216
  end
  object R1: TfrxReport
    Version = '6.2.11'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 44399.323783541700000000
    ReportOptions.LastChange = 44399.889742303200000000
    ScriptLanguage = 'C++Script'
    ScriptText.Strings = (
      ''
      '{'
      ''
      '}')
    Left = 376
    Top = 296
    Datasets = <
      item
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
      end
      item
        DataSet = frxDBDataset2
        DataSetName = 'frxDBDataset2'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Frame.Typ = []
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        Frame.Typ = []
        Height = 37.795300000000000000
        Top = 18.897650000000000000
        Width = 718.110700000000000000
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Top = 7.559060000000000000
          Width = 714.331170000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'LISTA CECURILOR')
          ParentFont = False
        end
      end
      object PageHeader1: TfrxPageHeader
        FillType = ftBrush
        Frame.Typ = []
        Height = 22.677180000000000000
        Top = 79.370130000000000000
        Width = 718.110700000000000000
        object Memo2: TfrxMemoView
          AllowVectorExport = True
          Width = 49.133890000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'NR.')
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          AllowVectorExport = True
          Left = 49.133890000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'NR. CEC')
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 143.622140000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'DATA CEC')
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Left = 238.110390000000000000
          Width = 102.047310000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'SUMA CEC')
          ParentFont = False
        end
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        Frame.Typ = []
        Height = 22.677180000000000000
        Top = 162.519790000000000000
        Width = 718.110700000000000000
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
        RowCount = 0
        object Memo6: TfrxMemoView
          AllowVectorExport = True
          Top = 3.779530000000000000
          Width = 49.133890000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[Line]')
          ParentFont = False
        end
        object Memo7: TfrxMemoView
          AllowVectorExport = True
          Left = 49.133890000000000000
          Top = 3.779530000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          DataField = 'NR_CEC'
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."NR_CEC"]')
          ParentFont = False
        end
        object Memo8: TfrxMemoView
          AllowVectorExport = True
          Left = 143.622140000000000000
          Top = 3.779530000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          DataField = 'DATA_CEC'
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."DATA_CEC"]')
          ParentFont = False
        end
        object Memo9: TfrxMemoView
          AllowVectorExport = True
          Left = 238.110390000000000000
          Top = 3.779530000000000000
          Width = 102.047310000000000000
          Height = 18.897650000000000000
          DataField = 'SUMA_CEC'
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."SUMA_CEC"]')
          ParentFont = False
        end
      end
      object PageFooter1: TfrxPageFooter
        FillType = ftBrush
        Frame.Typ = []
        Height = 22.677180000000000000
        Top = 291.023810000000000000
        Width = 718.110700000000000000
        object Memo10: TfrxMemoView
          AllowVectorExport = True
          Width = 714.331170000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Pagina [Page] din [TotalPages#]')
          ParentFont = False
        end
      end
      object ReportSummary1: TfrxReportSummary
        FillType = ftBrush
        Frame.Typ = []
        Height = 22.677180000000000000
        Top = 245.669450000000000000
        Width = 718.110700000000000000
        object Memo11: TfrxMemoView
          AllowVectorExport = True
          Top = 2.653370000000000000
          Width = 238.110390000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            'TOTAL')
          ParentFont = False
        end
        object Memo12: TfrxMemoView
          AllowVectorExport = True
          Left = 238.110390000000000000
          Top = 3.779530000000000000
          Width = 102.047310000000000000
          Height = 18.897650000000000000
          DataField = 'total'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold, fsUnderline]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."total"]')
          ParentFont = False
        end
      end
    end
  end
  object frxDBDataset1: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    DataSet = qcec
    BCDToCurrency = False
    Left = 320
    Top = 296
  end
  object qtotalcec: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      
        'select sum(suma_cec) as total from CEC where OPERATOR_ID=:OPERAT' +
        'OR_ID and cast(DATA_CEC as date) between :D1 and :D2'
      'and nr_cec>0')
    Left = 320
    Top = 224
    ParamData = <
      item
        Name = 'OPERATOR_ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'D1'
        DataType = ftDate
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'D2'
        DataType = ftDate
        ParamType = ptInput
        Value = Null
      end>
  end
  object DataSource1: TDataSource
    DataSet = qtotalcec
    Left = 264
    Top = 224
  end
  object frxDBDataset2: TfrxDBDataset
    UserName = 'frxDBDataset2'
    CloseDataSource = False
    DataSet = qtotalcec
    BCDToCurrency = False
    Left = 256
    Top = 296
  end
  object R2: TfrxReport
    Version = '6.2.11'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 44399.892800405100000000
    ReportOptions.LastChange = 44399.909195960640000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 416
    Top = 296
    Datasets = <
      item
        DataSet = frxDBDataset3
        DataSetName = 'frxDBDataset2'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Frame.Typ = []
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        Frame.Typ = []
        Height = 34.015770000000000000
        Top = 18.897650000000000000
        Width = 718.110700000000000000
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Left = 234.330860000000000000
          Top = 7.559060000000000000
          Width = 64.252010000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'NR. CEC : ')
        end
        object Memo2: TfrxMemoView
          AllowVectorExport = True
          Left = 298.582870000000000000
          Top = 7.559060000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          DataField = 'NR_CEC'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset2'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset2."NR_CEC"]')
        end
      end
      object PageHeader1: TfrxPageHeader
        FillType = ftBrush
        Frame.Typ = []
        Height = 18.897650000000000000
        Top = 75.590600000000000000
        Width = 718.110700000000000000
        object Memo3: TfrxMemoView
          AllowVectorExport = True
          Width = 30.236240000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'Nr.')
        end
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 30.236240000000000000
          Width = 83.149660000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Cod Produs')
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Left = 113.385900000000000000
          Width = 45.354360000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Cant.')
          ParentFont = False
        end
        object Memo6: TfrxMemoView
          AllowVectorExport = True
          Left = 158.740260000000000000
          Width = 37.795300000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Cost')
          ParentFont = False
        end
        object Memo7: TfrxMemoView
          AllowVectorExport = True
          Left = 196.535560000000000000
          Width = 49.133890000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Suma')
          ParentFont = False
        end
        object Memo8: TfrxMemoView
          AllowVectorExport = True
          Left = 245.669450000000000000
          Width = 64.252010000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Discount')
          ParentFont = False
        end
        object Memo9: TfrxMemoView
          AllowVectorExport = True
          Left = 309.921460000000000000
          Width = 102.047310000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Suma Discount')
          ParentFont = False
        end
        object Memo10: TfrxMemoView
          AllowVectorExport = True
          Left = 411.968770000000000000
          Width = 86.929190000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Suma Finala')
          ParentFont = False
        end
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        Frame.Typ = []
        Height = 18.897650000000000000
        Top = 154.960730000000000000
        Width = 718.110700000000000000
        DataSet = frxDBDataset3
        DataSetName = 'frxDBDataset2'
        RowCount = 0
        object Memo11: TfrxMemoView
          AllowVectorExport = True
          Width = 30.236240000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[Line]')
          ParentFont = False
        end
        object Memo12: TfrxMemoView
          AllowVectorExport = True
          Left = 30.236240000000000000
          Width = 83.149660000000000000
          Height = 18.897650000000000000
          DataField = 'cod'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."cod"]')
          ParentFont = False
        end
        object Memo13: TfrxMemoView
          AllowVectorExport = True
          Left = 113.385900000000000000
          Width = 45.354360000000000000
          Height = 18.897650000000000000
          DataField = 'CANTITATEA'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."CANTITATEA"]')
          ParentFont = False
        end
        object Memo14: TfrxMemoView
          AllowVectorExport = True
          Left = 158.740260000000000000
          Width = 37.795300000000000000
          Height = 18.897650000000000000
          DataField = 'PRET_VANZARE'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."PRET_VANZARE"]')
          ParentFont = False
        end
        object Memo15: TfrxMemoView
          AllowVectorExport = True
          Left = 196.535560000000000000
          Width = 49.133890000000000000
          Height = 18.897650000000000000
          DataField = 'SUMA'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."SUMA"]')
          ParentFont = False
        end
        object Memo16: TfrxMemoView
          AllowVectorExport = True
          Left = 245.669450000000000000
          Width = 64.252010000000000000
          Height = 18.897650000000000000
          DataField = 'DISCOUNT'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."DISCOUNT"]')
          ParentFont = False
        end
        object Memo17: TfrxMemoView
          AllowVectorExport = True
          Left = 309.921460000000000000
          Width = 102.047310000000000000
          Height = 18.897650000000000000
          DataField = 'SUMA_DISC'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."SUMA_DISC"]')
          ParentFont = False
        end
        object Memo18: TfrxMemoView
          AllowVectorExport = True
          Left = 411.968770000000000000
          Width = 86.929190000000000000
          Height = 18.897650000000000000
          DataField = 'SUMA_TOTAL'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."SUMA_TOTAL"]')
          ParentFont = False
        end
      end
      object ReportSummary1: TfrxReportSummary
        FillType = ftBrush
        Frame.Typ = []
        Height = 22.677180000000000000
        Top = 234.330860000000000000
        Width = 718.110700000000000000
        object Memo19: TfrxMemoView
          AllowVectorExport = True
          Width = 411.968770000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            'Total')
          ParentFont = False
        end
        object Memo20: TfrxMemoView
          AllowVectorExport = True
          Left = 411.968770000000000000
          Width = 86.929190000000000000
          Height = 18.897650000000000000
          DataField = 'SUMA_CEC'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            '[frxDBDataset2."SUMA_CEC"]')
          ParentFont = False
        end
      end
      object PageFooter1: TfrxPageFooter
        FillType = ftBrush
        Frame.Typ = []
        Height = 22.677180000000000000
        Top = 279.685220000000000000
        Width = 718.110700000000000000
        object Memo21: TfrxMemoView
          AllowVectorExport = True
          Top = 3.779530000000000000
          Width = 721.890230000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Pagina [line] din [TotalPages#]')
          ParentFont = False
        end
      end
    end
  end
  object frxDBDataset3: TfrxDBDataset
    UserName = 'frxDBDataset2'
    CloseDataSource = False
    DataSet = qvanzare
    BCDToCurrency = False
    Left = 184
    Top = 296
  end
  object frxcec: TfrxReport
    Version = '6.2.11'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 44400.817214791700000000
    ReportOptions.LastChange = 44400.846329861110000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 496
    Top = 296
    Datasets = <
      item
        DataSet = frxDBDataset3
        DataSetName = 'frxDBDataset2'
      end>
    Variables = <
      item
        Name = ' New Category1'
        Value = Null
      end
      item
        Name = 'TOTAL'
        Value = Null
      end>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 60.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 256
      LeftMargin = 5.000000000000000000
      RightMargin = 5.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Frame.Typ = []
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        Frame.Typ = []
        Height = 117.165430000000000000
        Top = 18.897650000000000000
        Width = 188.976500000000000000
        object Picture1: TfrxPictureView
          AllowVectorExport = True
          Left = 64.252010000000000000
          Top = 7.559060000000000000
          Width = 102.047310000000000000
          Height = 30.236240000000000000
          Frame.Typ = []
          Picture.Data = {
            0A54504E474F626A65637489504E470D0A1A0A0000000D494844520000005000
            00002408060000001EA2BD7A000000097048597300000EC300000EC301C76FA8
            64000015284944415478DABD5A077854D5D65DF74ECB2499F442424090128150
            A404E948955EA58BF828B6F7000B0AFA2388445004040B0F690AC883D023A00F
            A47729098416290649EFC9646632E5CEBC7DCEBD934C22D50FFE9B6FBECCDC39
            F79C7DD6597BEDBDCF19C14517948BBD150401EE5BF77A7FAFCBDD86FDFFFFB8
            EE65AF7BFC077DFF382EC1E97456A0C2DEB99CF27F9558692036B093BEB81788
            2A417CF2C0D1D86C744131955FCC7C6693284010C5F2360F9ACF6303D0255FDC
            28DC65004FC01E6480DC8F20CFF049E0878AAEEFC5249702F4BDEC7D320C543A
            94B2F260BF9402EBE924F88C1A004DED28D0F71C58915E3FDD398EDD7F1E2326
            0A32D8648C48AB6EB29930BE7E3F748E680EC929D162AB9E1082150C64E34B85
            2570FCFE072C474E42D7BC29F45DDBC0294910542ADEC691990BFBC56BB09E49
            86CFD881D0D48CE4F361363F56005D363B72874F46D9C9739072B2C94807A212
            7F85AE5943381C76A8D51A24107003FE3B855CC6414F89CA5AD37FC90A7F4314
            9207AD4394772879948B007C7C0656C2CFE9944725F00ADE9D8FD24D09706615
            C02EA5216CC932F84F1E2B4B4D6E21F2C6CF40D9E9F39072B338E4D593F74117
            13CD0116558F6F81B90B4BA526A4556B03C9944743E921E8F4883CBB0DDA98FA
            70487602448D9187676353CA4EE8F441904857048581F6B222ACEBF639C6D4E9
            010763DF13D442A72235ACFFF466FD60B970022A5508996146E8F285304C18C6
            DBD9AEA722A3E10BB4D6466AEF05D1C717116C3ECFD4E18B203C76065ACA905E
            AF3B513E9D40A1D521C6459EDF015DE36848C440157D1E74E003EC484900747E
            B2304B36FEFFAD67276061AB3739A82281277A44BA478E7EACBDB230CA8315F7
            A0E831EB8700C8EC38029663C720AA0D90ECC504E022F84D1AC1DB3852D390D9
            6A08A4823C6A4FAAECA5E7F3D136A80B974400AAC4871EF3A118E834999156A7
            2BA4EC4CBAA586A0D1CA03120325C941ABACC6A463F39170F357687506FE601D
            BFEA181FDD1F639EEE416EE1A80047508C63DA098F88CDEE8B154679A61ACA1D
            79617852E0F91CDD77334699187B36A3DD30949D384E00FA11D34A10FADD2218
            260EE7CDECB7FE44468B4170161580C98CA8F746049B8FC2C04AE0B03EEF3366
            79C4AF02AADB7E1940B305E904A0232BE32F00BA45D742DD10E7A052BAF5FD1B
            747791FE30C3EE9A5F32D7BA8F36B1675D4C1EA030B0FD70588E13033504A0BD
            0A807FDC4126012815E6FF154025C8F080749F31B94DCC5E06E17D52A00702E8
            1E50BA7907AEBC2240A382CB4681A4461884080A1A37FF8433BF989E51D37D1B
            B4E4F66C70CBCEFDB05D4CE1F7D43523A0EFD5995CA84EF96A5662A020C85133
            3D1B65FB4FC076E506506685101C00AF36CFC2AB632C04AD860700B6004C26FE
            36806E062A5220E516C0F2CB11D89253483C1D10694E5ECFB786576CD34A4039
            6EA74330F8420CF47B4406DAED64A406D983DF80717B3CD91F4464C945F0CCD9
            089C3305D97D27A174F70E32D39FC0B1C077C48BB01300968BA799E9DC0198F4
            8B5E7EF09F3A11819FBC45735255B80C338474A968DE32942C5E4193CE65FE2F
            83CBB34A0DA5288D11B46816F49D62C95D298AAA55152EFC8800F234870D4BA4
            30AEDE82C20F3F873DEB0E1F535E46F6D2C277D840F88CE80BEB897394D65D84
            35290921AB17C167484F4E2A51AD7E4806D2AA085A3572864F41E9E64D643045
            613B01F8F16C04CC7C133983DE40E98EED04AC1F5F55A7AB8CC1C5FBA175A355
            D672C05C0E1B24142260C2EB085E3157A920C0752FF7E5F760DCF0035F0441A5
            2503CB782A2540479F19F38A217AFB216CCB0A78F7EAC80DFFDB0C2442084488
            E2253F206FEAFB348696CCF35664C2AA2C2C7913CA38A82E30C0559C06D5B6AF
            85CFC0EE1532F05000DA1DDC3D3980F104A09600B4118073EE02A053E260399D
            26A87C43A0AA16023BB9B88B4015053D5C226B5284B0F52B6018DD9F1B50F8F1
            5728983D9B227D28816CE72CD6366C06F553117CE5A582745AED009E92A843C2
            1199B80BAAEAE1C86C379CF25606A0FF4302B89D00ACCB25C37A2A09991D8670
            A20B022D98B38C03A479AA16F7087B6A2A67A320EA18421C53A7CB82F06DAB64
            00C90B04F56307D0A00C6482CF80BE08FC6C3AD451D550762A11792FBF4BFA46
            40A8F404AE91F4A52D224E6D86949685F4463DE12C35CAE14903042F9809BF7F
            8DE5C6490545C81D3915E6BDFB0928031CF66C047DF02182E2DE46C673432951
            3EF9C80C6457CEB07FC1B8399E168DE4C86181CA3F00C1CBE3A07FA12307B06C
            EF51E4BD3613527E1E2DBC469E1731327CFBEA27C8403531C161A6DC310611A7
            B791D15EE549AB69DB5E640F9940B6E9B8CB0A3A2DA26E1F257D398FACC16369
            2232C3BC5AB741D0E20FE12C29E5115034F8C07AE11A0A26CF52DCCA04AF16B1
            8838B90599CF8F46D9B1230FCFC073DB791EC8CABF8CC6BD614FBF4320908D92
            09613F2E83EFA87EF048A860A22098337402D9A1E69F99343D59003501A48D05
            08FA7826023FFA279C541E82682EB07481226A46B301B0DD4821A632169622F2
            F41E588F9F47DEDBEF113303792011284DA1BAD2631AB21E09824A094636A822
            AA5359B6073943DE84E5D07E3EEE5F00BCC5001C08C9330F649548C37AB05DBB
            C9734497D9C438CEFB8BFA7D1F04BD0E2E654C1E5F69F1335A0DA6054C229BBD
            E9A3F93E009A18805DE0C866006AE44AE41C01D8580650A41442067023BD0FBE
            0F038B11F2E57C18A826A51A9003E8AE40B27BBE02D3BE5FB89EB9A85DB59F37
            C17EF977E4BE3B83D2AC402A8918402CFADAF9A4DD515ABEE754849C6CD10723
            EAC67EE48D7907E683FB1506D2B8CB2B00E4950867601E97065689449C210636
            AA4B635E276006F145A54214DA7AF511797117054A6DD57D3264751A0333B15C
            A5A26A472A45F856D2C0413DCAA3309F9B2703ED9C812A02C90B914909D044D7
            E61DB2D2277BD864984837EEC740A7BD08C18B3E85FF5BAF940BADBB78CFEA33
            01A63DBB9480508C080250CACE43CEB857C98543A8642C826F9F7EF09F45ECCD
            2FAA10696F3D9F9CD3584A7D3AF87B1DE586D95DC752297758A9448C085DB504
            BEE3062B41200D5904A083BB3041EF4DB570E24E68EA3EC573CD8CA6FDB87B0B
            829A270BD52FFCC27354A74D66BF486338983E37E94DED8A4807D57210D9B596
            B2804E5C9ACAD318560B330033980BB3528E89A6E842C4917878B56DCEF548F4
            F37D300315004316CF83DFD4719CB92C8377E7792CEDE0A22FFA923B5850FDCC
            6E0E4E5AA32EA4934C2FC93DAB8521F2E476686A552F4F60ADE72EC172F80402
            DE9E5429B175E781020F2234EE1773E1FFCE78FE9DEDE66D64B51CACB8B08AA7
            61D58ED17C5A35919F6D390865E7CFD0C2FA72F0BD7B7647E8C6A55005C849B2
            4473CE1B370DA6ED3B79709477814CB4484B61F8C7D0726DE7192E6720D139BD
            7E0FD8D352C9797484B615DABAF5A089A9C36402E109CB291ABE05E3C61F0940
            628B2D87B46E36D7BAEC81AF93E0EE50002C2406CE93194800BA44B96E7590A8
            A737EB0F178FB62EA8C2C2519DDC4615168C2C6292E9E07FA1D2847257548755
            87FF7B93A0AA1909FBA5EB945CAF82DD781B3E5D29B2C74DA3A4BA119786ECDE
            13283AFF4CEC3010CBA9DA090985B6750CE97603F84F7F15E90D7A724992E763
            23F6D585B6593D042F994D95C751648F7F156A4A9DD8E2B2CC411B1D03EFC1DD
            3963CD3BF6C1763599FAF6917D9A47613BD4C161D0B56D86808FA740F76C239E
            D40B4EABCD05D2B85CD214E38FDFD344C2B97EB95C76C2AE00FA261DB83B33CD
            316EDAA8B8701E25D21F21E0C33748CCFF89520EA0A2450BE3E0C7F6E524B99A
            60AE58BC7035F2A7CD84A80B84642D8061C470846D58CC57D24EA29ED979241C
            B9E9E4CA81E4A6653C172C4FC4E1430CF282DD76133E6DFB23E2E03AEEC6255F
            AF47EEBFA672F787C48E1A1C3C51D74634408D8CE3CA82AFF5988F8D7ACB41E0
            EBEF21E4DB5914C55F82E9D01E5A8B50EE252ECA202843E400B22DB00A1DA617
            25F73C1D74DA09C86244EE4B80BE5B3B39C052B474B11575FC9981ACCE23604D
            BD42A4F7E1E58C1325D0D56F8AA8947DC8EEF72A8CA4012242B82121D33F45D0
            BC7790D57D1C4A7FDD4CF703A97D2142E62F42C0FBAFC269B573D761655D46EC
            4038CC99BC2C63AFC8A33BE1D58EE481348D95892C55C97D6932ACC949BC3260
            2FB790B3C8CBAA01EF6E3D11BA7A3E545111BC8A7159ADC87D91F2B93D5B686C
            033DA3E69397908FF035ABA1EFD11E19AD0792575DA7EF7DB82BB320E4841111
            DBE2A1EF1C4BB244BABE6F0F7FB6023489DA98A13284D3780B605CB315A57B48
            FBE1C7DBB10A2562DF960A00F98988E2D38EB46C147EB204D65F4F91F6992086
            18A8F6EB8D00AA5F8DCB3690869DA52848BA6136C267701F1ED24BA8242A3B7F
            81EEFBC0692985EFE8C1F0EEDEBE3C8818576EA674832A065FAA95CBCCD0348C
            26179D582166EC4481B4522A2E45E9CA8D3027EC87E3561A8F926280011A1277
            EFA1BD284FEBCFFB93F704C1B7C6D83E66F1A7CB48ABF6C2994D4181B45AFB6C
            3D18268C863725C5F6D47414CD5982B24367E0225D53858740DBB119FCFE310A
            DA568D39338D2B37C114BF1B8EDF6FD3A2D8208606C1AB530BF84D194F89F7D3
            A4A325285EB082BBB533A780C6D05349F96D850BBB8F353D776A9D46130F1EAA
            20AA4D5942FC8807319E1BAAF77AAED2F163955D6229AF90D7ACA28F370F6070
            67171EED2A3D4F1397F20B21507B95BFE12F7D3A8B8D54ED9821D27C5882EFFE
            9E6FADB9C7CC2DE0515EA44052DEC663F395C509275546A2AF0F5F28C16D838B
            ED4843D997538E083D776CE58104126AA77C88A418CDB74B051EE394C31E97BC
            A92B0A7C671A4AEACBFB737926C6827C04798F3D411678D8E6ABE8393E3FB614
            211FF809E547ACDC1E172AEDE9F1F6CC3EBE3F2BB1A4ACF2F76C4B4C908F40CB
            F72145B1D266A9E470C866AAD47221F0977DC38AF3C10A0656D986F7DCFDBDDB
            61F5C3B2B052DF4A44BBDF55E92CDAE9F11C2A16A1EAF8EEAD7EF7BEA2AB6A3F
            1EDF575AB04A9DA0A2EF2ACF96B7BF4B1FE500DE0D00CF49DD28498745B2A271
            E0D3FCDEAE3B2770B5F8365EAB3F00BE1A3DE625AF4380C61729257730A45667
            B40B6B8C6C730149B284087D88CC1CC80C667FF2198A50BEC1CA3EB3E3D04D7F
            ECC7CE3F0E60719B77E8B9E072F09C0ACBD965773AF0F66F5F2344E78F4F9A4F
            50761CE589395C12E31C0E675FC0A582EB1853B71702B406E5B855944F0D3D0E
            BE280BAED4379BF73B67BF8141ADC7DCE613956513EEBF237D2F36B041993BDE
            284943EB5D13C9700967FAAD44B47F4D74FE65328EDC398A5B237F466D43040E
            652662FE85EF11EE1B8E052DDF409857009EDBF51ACC92051707FCF040C6BAAF
            15293F615DCA0EACE8340BF5FD6A70575509954FD1D8E9DF9083FF8720026675
            FB19E513F73CEF9D727A0996FEB6146747EE418B90E8FB7A48D56BF8A159D08A
            6AAC69FF011FDB7D94FAD000BA6F3156A88915F32EAEC307C73FE3F48D6B330D
            339ABC8481073EC0CF69A77067D8363ED837D7B6219156BC863E08EF361E83BD
            E967F0C6F17994A7E9D1A7461B0CABF53CB6A41EC4B8BA7DD020A016A69F598A
            F1D183702EEF1AD2CCB9C4125F9CCFFF1D7D6BB4C3755AB0693123518DFA6293
            DC9A7A183F5CDF8570622473B309F5FBE374EE1558292F9BD678143FB761EDD8
            E73989AB71B93815C536138E65252279D07A54F70EC5CC73FFC6491AEB85EAB1
            789FECD7AB749CB35B6E1FC2BAEBBB114E6D5CC4DE97EAF64672E14D98281F65
            36B899FDC80C64D476BB5ACCCEB130A8BCB8FB1B1D565C25A306EC9F81843F8F
            226FE46E645AF2F1C5A58D08F1F2C7C2A435E856B30319DA1AB3CE7C05073D17
            1BF20CBA45B6C42C02745E878FD035A20562D777C3ECE7E7E260E6791CBEF90B
            5A91DB3F17D288F7B5E5CA669C7C712B9E0B6BC417F3FB1B7BF043CA4E9C2CBC
            051BBDBEEABE008B2FC7A3D46141D6F09DE52C9D7CFA4B7C75E65B7421B7BD55
            9A89545A884462FFFBE796E16C76325E891E8885892BF07E8BD730BFE56B0AE3
            13F0232DCE6F45A9B0E4A7208E6C5A43801AED16A41339547C83585EA0BB8178
            4F06724D22A34EE45C42FB1D633033763207358EB42765E42ECC4A5C858DA9FB
            51482EC2DACE25E0EE98F3703CE7226CE462F9A376E3D984F1C404236E0D8DE7
            40F5D83E06DF769D8FF6E14DD064431FC475F890DF3F969D847402C24FEB83B7
            7EFB0A4B2FAE45D2908D8809781A76620563F8A9DCABE8BC731C7A3FDD151B3A
            CD46DDAD231048AC4D1EB896DB5C6C2B459DAD54E1E8027065F08FF82871253E
            219BE23BCFC5B00333101BDE14DD235A22EEFC728C8E1E80F51D67C22ED9A151
            69708E98DF61C7CB78A1367909015867CB7018343E243DDF976BE32331D00D20
            73DFA9A7976249D22A68C99D584BBB390771EDA623A5F84FAC2556DC1E918039
            A47DABCEAFC4F21E8BF0E5E54DC82E2BC41F4337A315E92673854B3449B6107D
            08C0D9045ADBB018F420233F7F3E0EFB33CFE254DE15DC18B411013A5FBC7EEA
            0BACBA148FD3C4F256A10DB8C0A79666A0ED4F93C82DEC38D07705B96430A2B7
            8D422005910BFD57434300171180B5B6BC88480A58C77A7F83978FC6614FDA09
            6CEDF2290693DC30D998DA70184F8FBA9037D4F28DE0E0DC26A6B6D93509222D
            FADEDEDFE2299F7034DA3116DE6A2FEA7B0DBCD4DA726F7C68064A4E3942E612
            107569A28C892B49AC5907E3C9B0607D2026D6EB87E9C7E62124B036BA904BC6
            DFDC8B66E4AA255453DECABA8005140432CDF9587486A22519BFBEF31C7C9EBC
            0107C8ED05322E5467C0510263C4E159482AA0726FD876542360E65F5C8F1914
            2006C48CC28EAE9F727BA69FFD373E3BB5105ABF9AD0502630B5E9CBB85A741B
            DB2EFD076B7A7D8D71F57AF1459F46D173E1D96508F1AFCDE5E45A561246347C
            11F5FCA3F0C9B9EFD02EA2393F5B5E4D0460018ACD671AB9FC17D4B72EA036D4
            E4B6936246D0826561FBE5FFE0BB9E4B30B17E3F1EB45864BFDB8F92EE0AA053
            49980BAD46ECBE731C357CABA153B566FCBB933997718DD2977E35DAE2684E32
            CA8861036B76C4EEB493C821C07B46C6E204A5109D09D43062ED3AD22F515061
            749D9EDC902DA9078895160A2CEDF11445ECBDE9BFA18404BF2FF5E7A5D6C142
            1ABB9582CD33047A4B5A10665E06E922EB93252B16BB193141F510A4F3C35162
            EF0B353AD03801BC1DFB8BA714C84C200FABD58552ADE3A8E7174551F8199AC7
            099CCDBB4AEF1BA0070512B520FF822B9D02D849D24797C0FAB6E0192244B857
            208E50DF3DC9C670228BE76F721E3A88540DF32CA561D7E3FCE99AD3A3B27992
            D793FCD5EC3D35D09D69B3C494F9BF5A018EB1C8C5A39E8A74520695ADA64379
            CFDCDD1D80D8730E8F366C20F60C3FE9E03F4412CBFBE38CF018937DE7CEFF98
            06B13EDD9728C8352CD7698FE7B87DE576C8F6F11F3C29D98453F90194BB5FF6
            DCFDFA667D88554ACEAAD7FF00237A4418B34671720000000049454E44AE4260
            82}
          HightQuality = False
          Transparent = False
          TransparentColor = clWhite
        end
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Top = 64.252010000000000000
          Width = 185.196970000000000000
          Height = 49.133890000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'S.R.L.  "CASUTA TA"'
            'IDNO   10293020391'
            'Adr. or.Chisinau, str.Cantemir 8')
          ParentFont = False
        end
        object Memo2: TfrxMemoView
          AllowVectorExport = True
          Top = 113.385900000000000000
          Width = 196.535560000000000000
          Height = 3.779530000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftTop]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo14: TfrxMemoView
          AllowVectorExport = True
          Top = -18.897650000000000000
          Width = 75.590600000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'Bon Fiscal : ')
        end
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        Frame.Typ = []
        Height = 64.252010000000000000
        Top = 196.535560000000000000
        Width = 188.976500000000000000
        DataSet = frxDBDataset3
        DataSetName = 'frxDBDataset2'
        RowCount = 0
        object frxDBDataset2PRODUS: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Top = 7.559060000000000000
          Width = 98.267780000000000000
          Height = 18.897650000000000000
          DataField = 'PRODUS'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftTop]
          Memo.UTF8W = (
            '[frxDBDataset2."PRODUS"]')
          ParentFont = False
        end
        object frxDBDataset2CANTITATEA: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 98.267780000000000000
          Top = 7.559060000000000000
          Width = 90.708720000000000000
          Height = 18.897650000000000000
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftTop]
          HAlign = haRight
          Memo.UTF8W = (
            '[frxDBDataset2."CANTITATEA"]x[frxDBDataset2."PRET_VANZARE"]')
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Top = 25.339440000000000000
          Width = 188.976500000000000000
          Height = 18.897650000000000000
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftTop]
          HAlign = haRight
          Memo.UTF8W = (
            'Discount - [frxDBDataset2."SUMA_DISC"]')
          ParentFont = False
          Formats = <
            item
            end
            item
            end>
        end
        object Memo4: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Top = 45.354360000000000000
          Width = 188.976500000000000000
          Height = 18.897650000000000000
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftTop]
          HAlign = haRight
          Memo.UTF8W = (
            '[frxDBDataset2."SUMA_TOTAL"]')
          ParentFont = False
        end
      end
      object ReportSummary1: TfrxReportSummary
        FillType = ftBrush
        Frame.Typ = []
        Height = 124.724490000000000000
        Top = 321.260050000000000000
        Width = 188.976500000000000000
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftTop]
          Memo.UTF8W = (
            'TOTAL')
          ParentFont = False
        end
        object Memo6: TfrxMemoView
          AllowVectorExport = True
          Left = 94.488250000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftTop]
          Memo.UTF8W = (
            '[TOTAL]')
          ParentFont = False
        end
        object Memo7: TfrxMemoView
          AllowVectorExport = True
          Left = -71.811070000000000000
          Top = 18.897650000000000000
          Width = 41.574830000000000000
          Height = 18.897650000000000000
          DataField = 'CLIENT'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset2'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset2."CLIENT"]')
        end
        object Memo8: TfrxMemoView
          AllowVectorExport = True
          Top = 37.795300000000000000
          Width = 52.913420000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'CASIER:')
        end
        object frxDBDataset2OPERATOR: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 60.472480000000000000
          Top = 37.795300000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          DataField = 'OPERATOR'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset2'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset2."OPERATOR"]')
        end
        object Memo9: TfrxMemoView
          AllowVectorExport = True
          Top = 18.897650000000000000
          Width = 60.472480000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'CLIENT: ')
        end
        object Memo10: TfrxMemoView
          AllowVectorExport = True
          Left = 60.472480000000000000
          Top = 18.897650000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          DataField = 'CLIENT'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset2'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset2."CLIENT"]')
        end
        object Memo11: TfrxMemoView
          AllowVectorExport = True
          Top = 56.692950000000000000
          Width = 185.196970000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'DATA: [Date]  ORA: [Time]')
          Formats = <
            item
            end
            item
            end>
        end
        object Memo12: TfrxMemoView
          AllowVectorExport = True
          Left = 41.574830000000000000
          Top = 102.047310000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'Va Multumim!!!')
        end
        object Memo13: TfrxMemoView
          AllowVectorExport = True
          Top = 75.590600000000000000
          Width = 75.590600000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'Bon Fiscal : ')
        end
        object Memo15: TfrxMemoView
          AllowVectorExport = True
          Left = 75.590600000000000000
          Top = 75.590600000000000000
          Width = 109.606370000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haRight
          Memo.UTF8W = (
            'NR. [frxDBDataset2."NR_CEC"]')
          ParentFont = False
        end
        object Memo16: TfrxMemoView
          AllowVectorExport = True
          Top = 120.944960000000000000
          Width = 192.756030000000000000
          Height = 3.779530000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftTop]
          HAlign = haRight
          ParentFont = False
        end
      end
    end
  end
  object frxDBDataset4: TfrxDBDataset
    UserName = 'frxDBDataset4'
    CloseDataSource = False
    DataSet = qvanzare
    BCDToCurrency = False
    Left = 560
    Top = 296
  end
end
